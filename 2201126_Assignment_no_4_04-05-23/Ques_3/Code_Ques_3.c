#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

char peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infix_to_prefix(char infix[], char prefix[]) {
    int i, j = 0;
    Stack opstack;
    opstack.top = -1;
    strrev(infix);
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalpha(infix[i])) {
            prefix[j++] = infix[i];
        }
        else if (is_operator(infix[i])) {
            while (opstack.top != -1 && precedence(peek(&opstack)) >= precedence(infix[i])) {
                prefix[j++] = pop(&opstack);
            }
            push(&opstack, infix[i]);
        }
        else if (infix[i] == ')') {
            push(&opstack, infix[i]);
        }
        else if (infix[i] == '(') {
            while (peek(&opstack) != ')') {
                prefix[j++] = pop(&opstack);
            }
            pop(&opstack);
        }
    }
    while (opstack.top != -1) {
        prefix[j++] = pop(&opstack);
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix_to_prefix(infix, prefix);
    printf("The prefix expression is: %s\n", prefix);
    return 0;
}
