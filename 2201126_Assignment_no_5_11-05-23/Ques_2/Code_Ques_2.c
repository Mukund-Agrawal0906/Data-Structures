#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max_Size 100

typedef struct
{
    int stack[Max_Size];
    int top;
}Stack;

typedef struct
{
    int queue[Max_Size];
    int Front;
    int Rear;
}Queue;

int pop(Stack *s)
{
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

void push(Stack *s, int item)
{
    if (s->top == Max_Size - 1) {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = item;
}

void init(Queue *q){
    q->Front=-1;
    q->Rear=-1;
}

void enqueue(Queue *q, int item){
    if (q->Rear==Max_Size-1){
        printf("Queue OverFlow!\n");
        exit(EXIT_FAILURE);
    }
    else{
        if(q->Front==-1 && q->Rear==-1){
            q->Front=0;
            q->Rear=0;
        }
        else{
            q->Rear++;
        }
        q->queue[q->Rear]=item;
    }
}

int dequeue(Queue *q){
    if(q->Front==-1){
        printf("Queue Underflow!\n");
        exit(EXIT_FAILURE);
    }
    else{
        return q->queue[q->Front++];
    }
}


int main()
{
    int n,p;
    printf("Enter the Decimal Number to be converted \n");
    scanf("%d",&n);
    p=n;
    Stack binary;
    binary.top=-1;

    Queue b;
    init(&b);

    while(n!=0){
        push(&binary,n%2);
        n=n/2;
    }
    while(binary.top!=-1){
        enqueue(&b,pop(&binary));
    }

    int array[Max_Size];
    int i=0;
    while((b.Front<=b.Rear) && (b.Rear!=-1) ){
        array[i++]=dequeue(&b);
    }

    printf("The Binary Number of %d is \n",p);
    for(int j=0;j<i;j++){
        printf("%d",array[j]);
    }
    printf("\n");
    
    return 0;
}