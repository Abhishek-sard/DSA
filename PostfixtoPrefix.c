#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure to hold strings
struct Stack {
    int top;
    unsigned capacity;
    char* array[MAX];
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

// Stack is empty when top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. Increases top by 1
void push(struct Stack* stack, char* item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack. Decreases top by 1
char* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert postfix to prefix expression
void postfixToPrefix(char* exp) {
    int length = strlen(exp);

    // Create a stack of capacity equal to the length of the expression
    struct Stack* stack = createStack(length);

    // Traverse the postfix expression
    for (int i = 0; i < length; i++) {
        // If the character is an operand, push it to the stack
        if (isalnum(exp[i])) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = exp[i];
            operand[1] = '\0';
            push(stack, operand);
        }
        // If the character is an operator
        else if (isOperator(exp[i])) {
            // Pop two operands from the stack
            char* op1 = pop(stack);
            char* op2 = pop(stack);

            // Create a new string with the operator at the front
            char* result = (char*)malloc(strlen(op1) + strlen(op2) + 2 * sizeof(char));
            result[0] = exp[i];
            result[1] = '\0';
            strcat(result, op2);
            strcat(result, op1);

            // Push the result back to the stack
            push(stack, result);

            // Free the allocated memory for popped operands
            free(op1);
            free(op2);
        }
    }

    // The remaining item in the stack is the prefix expression
    char* prefix = pop(stack);
    printf("Prefix expression: %s\n", prefix);

    // Free the allocated memory for the prefix expression
    free(prefix);
    // Free the stack
    free(stack);
}

// Driver program to test above functions
int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    postfixToPrefix(exp);

    return 0;
}
