/*
Develop a menu driven program to convert infix expressions to postfix
expression and evaluate the postfix expression.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_SIZE 25


typedef struct{
    char exp[MAX_SIZE];
    int top;
} Stack;


Stack *initialize(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack){
        printf("Memory allocation for stack failed!\n");
        exit(1);
    }
    stack->top = -1;

    return stack;
}


void push(Stack *stack, char c){
    stack->exp[++stack->top] = c;
}


int pop(Stack *stack){
    if (stack->top == -1)
        return -1;
    return stack->exp[stack->top--];
}

int peek(Stack *stack){
    if (stack->top == -1)
        return -1;
    return stack->exp[stack->top];
}


int is_empty(Stack *stack){
    if (stack->top == -1){
        return 1;
    }
    return 0;
}


int is_op(char c){
    switch (c){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


int precedence(char op){
    switch (op){
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


char ass(char op){
    if (op == '^')
        return 'R';
    return 'L';
}


void convert(char infix[], Stack *postfix){
    Stack *op = initialize();

    int i;
    for (i = 0; infix[i] != '\0'; i++){
        char c = infix[i];

        if (c == '('){
            push(op, c);
        }
        else if (c == ')'){
            while (peek(op) != '('){
                push(postfix, pop(op));
            }
            pop(op);

        }
        else if (is_op(c)){
            if (op->top == -1){
                push(op, c);
            }
            else{
                if (precedence(c) > precedence(peek(op))){
                    push(op, c);
                }
                else{
                    while (precedence(c) <= precedence(peek(op))){
                        push(postfix, pop(op));
                    }
                    push(op, c);
                }
            }
        }
        else{
            push(postfix, c);
        }
    }
    while (!is_empty(op)){
        push(postfix, pop(op));
    }
    push(postfix, '\0');
    
    free(op);
}


float evaluate_postfix(char postfix[]){
    int i;
    Stack *result = initialize();

    for (i = 0; postfix[i] != '\0'; i++){
        char c = postfix[i];

        if (!is_op(c)){
            push(result, c);
        }
        else{
            int a = pop(result) - '0';
            int b = pop(result) - '0';
            switch (c){
                case '^':
                    push(result, pow(a, b) + '0');
                    break;

                case '*':
                    push(result, (a*b) + '0');
                    break;
                
                case '/':
                    push(result, (a/b) + '0');
                    break;

                case '+':
                    push(result, (a+b) + '0');
                    break;

                case '-':
                    push(result, (a-b) + '0');
                    break;
                
                default:
                    break;
            }
        }
    }
    
    return pop(result) - '0';
}


int main(){
    char infix[MAX_SIZE];

    printf("\nMAIN MENU :>\n\n");
    printf("1. Infix to Postfix\n");
    printf("2. Evaluate Postfix\n");
    printf("0. Exit\n");

    int choice;
    do{
    Stack *postfix = initialize();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:{
                printf("Enter infix expression: ");
                scanf("%s", infix);
                convert(infix, postfix);
                printf("Postfix: %s\n", postfix->exp);
                free(postfix);
                break;
            }
            case 2:{
                printf("Enter postfix to evaluate: ");
                scanf("%s", postfix->exp);
                printf("Result: %f\n", evaluate_postfix(postfix->exp));
                free(postfix);
                break;
            }
            case 0:{
                printf("Exiting...\n");
                free(postfix);
                break;
            }
            default:{
                printf("Invalid choice!\n");
            }
        } 
    } while (choice != 0);

    return 0;
}
