// //scan the given postfix expression from left ot right.
// //if character is operand push it into the stack
// //if the char is an operator,pop the two values from stack.
// //concatenate operator with two values(2 nd top vlue + operator + 1st value)
// //push this resulting strinng back into the stack
// // repet processs until the end of postfix now the value is stack in infix expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

 #define MAX_SIZE 100
char *pop(char *stack[], int *top)
{
    if (*top = -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[(*top)--];
}
int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
void postfix_to_infix(char *postfix, char *infix)
{
    char *stack[MAX_SIZE];
    int top = -1;
    int i = 0;
    while (postfix[i]  != '\0')
    {
        if (is_operator(postfix[i]))
        {
            char *op2 = pop(stack, &top);
            char *op1 = pop(stack, &top);
            char *temp = (char *)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            push(stack, &top, temp);
        }
        else{
            char * operand = (char *)malloc(2);
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(stack, &top, operand);
        }
        i++;
    }
    strcpy(infix,pop(stack,&top));
}
void main(){
    char postfix[MAX_SIZE],infix[MAX_SIZE];

    printf("Enter the postfi expression:");
    scanf("%s", postfix);

    postfix_to_infix(postfix,infix);
    printf("infix expression:%s\n", infix);
    getch();
}
