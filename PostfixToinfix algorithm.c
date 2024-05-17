//scan the given postfix expression from left ot right.
//if character is operand push it into the stack
//if the char is an operator,pop the two values from stack.
//concatenate operator with two values(2 nd top vlue + operator + 1st value)
//push this resulting strinng back into the stack
// repet processs until the end of postfix now the value is stack in infix expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Function to push a string onto the stack
void push(char stack[MAX_SIZE][MAX_SIZE], int *top, char *item) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++(*top)], item);
}

// Function to pop a string from the stack
void pop(char stack[MAX_SIZE][MAX_SIZE], int *top, char *result) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    strcpy(result, stack[(*top)--]);
}

// Function to check if a character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert postfix expression to infix expression
void postfix_to_infix(char *postfix, char *infix) {
    char stack[MAX_SIZE][MAX_SIZE];
    int top = -1;
    char op1[MAX_SIZE], op2[MAX_SIZE], temp[MAX_SIZE];

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {  // If the character is an operand
            char operand[2] = {postfix[i], '\0'};
            push(stack, &top, operand);
        } else if (is_operator(postfix[i])) {  // If the character is an operator
            pop(stack, &top, op2);
            pop(stack, &top, op1);
            snprintf(temp, MAX_SIZE, "(%s%c%s)", op1, postfix[i], op2);
            push(stack, &top, temp);
        }
    }

    pop(stack, &top, infix);  // The resulting infix expression
}

int main() {
    char postfix[MAX_SIZE], infix[MAX_SIZE];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    postfix_to_infix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}

