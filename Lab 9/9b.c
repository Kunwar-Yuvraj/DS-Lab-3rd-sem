/*
Develop a menu driven program to convert infix expression to prefix and
evaluate the prefix expression.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} op_stack;

void init_op_stack(op_stack *s) {
    s->top = -1;
}

void push(op_stack *s, char op) {
    s->stack[++s->top] = op;
}

char pop(op_stack *s) {
    return s->stack[s->top--];
}

char peek(op_stack *s) {
    return s->stack[s->top];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int get_precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infix_to_prefix(char infix[], char prefix[]) {
    op_stack op_stack;
    init_op_stack(&op_stack);

    int i, j;
    for (i = strlen(infix) - 1, j = 0; i >= 0; i--) {
        if (
            (infix[i] >= 'a' && infix[i] <= 'z') 
            || (infix[i] >= 'A' && infix[i] <= 'Z')
            ) {
            prefix[j++] = infix[i];
        } 
        else if (infix[i] == '(') {
            push(&op_stack, infix[i]);
        }
        else if (infix[i] == ')') {
            while (peek(&op_stack) != '(') {
                prefix[j++] = pop(&op_stack);
            }
            pop(&op_stack);
        } 
        else if (is_operator(infix[i])) {
            while (
                get_precedence(infix[i]) <= get_precedence(peek(&op_stack))
                && infix[i] != '^'
            ) {
                prefix[j++] = pop(&op_stack);
            }
            push(&op_stack, infix[i]);
        }
    }

    while (op_stack.top != -1) {
        prefix[j++] = pop(&op_stack);
    }

    prefix[j] = '\0';

    int len = strlen(prefix);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}



int evaluate_prefix(char prefix[]) {
    op_stack opstack;
    init_op_stack(&opstack);

    int i;
    for (i = 0; prefix[i] != '\0'; i++) {
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            push(&opstack, prefix[i] - '0');
        }
        else {
            int op2 = pop(&opstack);
            int op1 = pop(&opstack);

            switch (prefix[i]) {
                case '+':
                    push(&opstack, op1 + op2);
                    break;
                case '-':
                    push(&opstack, op1 - op2);
                    break;
                case '*':
                    push(&opstack, op1 * op2);
                    break;
                case '/':
                    push(&opstack, op1 / op2);
                    break;
                case '^':
                    push(&opstack, (int)pow(op1, op2));
                    break;
            }
        }
    }

    return pop(&opstack);
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("\nMenu:\n");
    printf("1. Convert Infix to Prefix\n");
    printf("2. Evaluate Prefix Expression\n");
    printf("0. Exit\n");

    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                infix_to_prefix(infix, prefix);
                printf("Prefix expression: %s\n", prefix);
                break;
            case 2:
                printf("Enter the prefix expression: ");
                scanf("%s", prefix);
                strrev(prefix);
                int result = evaluate_prefix(prefix);
                printf("Result: %d\n", result);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
