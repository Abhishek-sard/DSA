#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Push operation
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {  // Check if stack is full
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

// Pop operation
int pop(struct Stack* stack) {
    if (stack->top == -1) {  // Check if stack is empty
        printf("Stack Underflow\n");
        return -1;  // Return an error value
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

// Display stack
void display(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack elements after pushes: ");
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    printf("Stack elements after pop: ");
    display(&stack);

    return 0;
}
