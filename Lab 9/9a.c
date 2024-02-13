/*
Develop a menu driven program to convert infix expressions to postfix
expression and evaluate the postfix expression.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} op_stack;

void init_op_stack(op_stack *s) {
    s->top = -1;
}

void push_operator(op_stack *s, char op) {
    s->stack[++s->top] = op;
}

char pop_operator(op_stack *s) {
    return s->stack[s->top--];
}

char peek_operator(op_stack *s) {
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

void infix_to_postfix(char infix[], char postfix[]) {
    op_stack op_stack;
    init_op_stack(&op_stack);

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (
            (infix[i] >= 'a' && infix[i] <= 'z') 
            || (infix[i] >= 'A' && infix[i] <= 'Z')
        ) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push_operator(&op_stack, infix[i]);
        }
        else if (infix[i] == ')') {
            while (peek_operator(&op_stack) != '(') {
                postfix[j++] = pop_operator(&op_stack);
            }
            pop_operator(&op_stack);
        }
        else if (is_operator(infix[i])) {
            while (
                get_precedence(infix[i]) <= get_precedence(peek_operator(&op_stack))
            ) {
                postfix[j++] = pop_operator(&op_stack);
            }
            push_operator(&op_stack, infix[i]);
        }
    }

    while (op_stack.top != -1) {
        postfix[j++] = pop_operator(&op_stack);
    }

    postfix[j] = '\0';
}

int evaluate_postfix(char postfix[]) {
    op_stack operand_stack;
    init_op_stack(&operand_stack);

    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push_operator(&operand_stack, postfix[i] - '0');
        }
        else {
            int op2 = pop_operator(&operand_stack);
            int op1 = pop_operator(&operand_stack);

            switch (postfix[i]) {
                case '+':
                    push_operator(&operand_stack, op1 + op2);
                    break;
                case '-':
                    push_operator(&operand_stack, op1 - op2);
                    break;
                case '*':
                    push_operator(&operand_stack, op1 * op2);
                    break;
                case '/':
                    push_operator(&operand_stack, op1 / op2);
                    break;
                case '^':
                    push_operator(&operand_stack, (int)pow(op1, op2));
                    break;
            }
        }
    }

    return pop_operator(&operand_stack);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("\nMenu:\n");
    printf("1. Convert Infix to Postfix\n");
    printf("2. Evaluate Postfix Expression\n");
    printf("3. Exit\n");

    int choice;
    while (1) {
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                infix_to_postfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;
            case 2:
                printf("Enter the postfix expression: ");
                scanf("%s", postfix);
                int result = evaluate_postfix(postfix);
                printf("Result: %d\n", result);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
