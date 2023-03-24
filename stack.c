#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit() function

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define a stack data structure
struct stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void init_stack(struct stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int is_empty(struct stack *s) {
    return (s->top == -1);
}

// Function to check if the stack is full
int is_full(struct stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct stack *s, int x) {
    if (is_full(s)) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = x;
}

// Function to pop an element from the stack
int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

// Function to evaluate a postfix expression
int evaluate_expression(char *expression) {
    struct stack s;
    init_stack(&s);
    char *token = expression;
    int operand1, operand2, result;
    while (*token) {
        if (isdigit(*token)) {
            push(&s, *token - '0');
        } else if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (*token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(&s, result);
        }
        token++;
    }
    return pop(&s);
}

int main() {
    char expression[] = "521+4*+3-";
    printf("Result: %d\n", evaluate_expression(expression));
    return 0;
}
