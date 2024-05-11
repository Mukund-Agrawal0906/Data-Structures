#include<stdio.h>
#include<stdlib.h>

#define Max_Size 100000

int count=0;

typedef struct {
    int data[Max_Size];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


int is_empty(Stack *s) {
    return s->top == -1;
}


int is_full(Stack *s) {
    return s->top == Max_Size - 1;
}


void push(Stack *s, int elem) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = elem;
}


int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    init(&s);

    Stack a;
    init(&s);

    int x;
    int y=0;
    printf("Enter the number(It should be greater than 0 with no leading zeros) \n");
    printf("Caution!!! Number of digits not more than 100000 \n");
    scanf("%d",&x);
    int z=x;
    if(x<=0){
        return -1;
    }
    while (z>0){
        int r=0;
        r=z%10;
        push(&s,r);
        z=z/10;
        y++;
    }
    
    if(y>100000){
        return -1;
    }
    int y1=y;

    while(y1>0){
        int d=pop(&s);
        push(&a,d);
        y1--;
    }
    int r;
    printf("Enter the number of the digits to be truncated\n");
    scanf("%d",&r);
    int r1=r;

    while(r1>0){
        int d1=pop(&a);
        r1--;
    }
    int y2=y-r;
    while(y2>0){
        int d2=pop(&a);
        push(&s,d2);
        y2--;
    }
    int y3=y-r;
    while (y3>0){
        printf("%d",pop(&s));
        y3--;
    }
    printf("\n");

    return 0;
}