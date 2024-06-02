#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack type
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. Increases top by 1
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack. Decreases top by 1
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// A utility function to check if the given character is operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to reverse a string
void reverse(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* exp, char* result) {
    int i, k = -1;

    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    if (!stack)
        return;

    for (i = 0; exp[i]; ++i) {
        // If the scanned character is an operand, add it to output
        if (isOperand(exp[i]))
            result[++k] = exp[i];

        // If the scanned character is '(', push it to the stack
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is ')', pop and output from the stack
        // until an '(' is encountered
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                result[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // invalid expression
            else
                pop(stack);
        } else { // an operator is encountered
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                result[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        result[++k] = pop(stack);

    result[++k] = '\0';
}

// Function to convert infix to prefix
void infixToPrefix(char* exp, char* result) {
    // Reverse the infix expression
    reverse(exp);

    // Replace '(' with ')' and vice versa
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }

    // Convert reversed infix expression to postfix expression
    infixToPostfix(exp, result);

    // Reverse the postfix expression to get the prefix expression
    reverse(result);
}

// Driver program to test above functions
int main() {
    char exp[MAX];
    char result[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPrefix(exp, result);
    printf("Prefix expression: %s\n", result);

    return 0;
}
