#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100


typedef struct {
    char data[MAX_LEN];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


int is_empty(Stack *s) {
    return s->top == -1;
}


int is_full(Stack *s) {
    return s->top == MAX_LEN - 1;
}


void push(Stack *s, char elem) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = elem;
}


char pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}


int is_balanced(char *str) {
    Stack s;
    init(&s);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&s, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (is_empty(&s)) {
                return 0;
            } else {
                char top_elem = pop(&s);
                if ((str[i] == ')' && top_elem != '(') || 
                    (str[i] == ']' && top_elem != '[') || 
                    (str[i] == '}' && top_elem != '{')) {
                    return 0;
                }
            }
        }
    }
    return is_empty(&s);
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string of parentheses: ");
    fgets(str, MAX_LEN, stdin);
    if (is_balanced(str)) {
        printf("The string is balanced\n");
    } else {
        printf("The string is not balanced\n");
    }
    return 0;
}