#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX][MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char *item) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    strcpy(s->stack[++(s->top)], item);
}

char* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return s->stack[(s->top)--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void prefixToPostfix(char *prefix) {
    Stack s;
    initStack(&s);

    int length = strlen(prefix);

    // Traverse the prefix expression in reverse order
    for (int i = length - 1; i >= 0; i--) {
        // If the character is an operand, push it to the stack
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(&s, operand);
        } 
        // If the character is an operator
        else if (isOperator(prefix[i])) {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            
            char expr[MAX];
            sprintf(expr, "%s%s%c", op1, op2, prefix[i]);

            push(&s, expr);
        }
    }

    // The final postfix expression will be at the top of the stack
    printf("Postfix Expression: %s\n", pop(&s));
}

int main() {
    char prefix[MAX];
    
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    
    prefixToPostfix(prefix);
    
    return 0;
}
