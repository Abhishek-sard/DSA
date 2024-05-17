#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void push(char *stack, int *top, char item) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = item;
}

char pop(char *stack, int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

void infix_to_postfix(char *infix, char *postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(stack, &top, infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top); // Pop '(' from the stack
        } else if (is_operator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        } else {
            postfix[j++] = infix[i];
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0'; // Add null terminator to make it a valid string
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
