#include<stdio.h>
#include<stdlib.h>

#define Max_Size 100

int count=0;

typedef struct {
    int data[Max_Size];
    int top;
} Stack;


struct node   
{  
    int data;   
    struct node *next;  
};  

struct node *front;  
struct node *rear; 


void insert(int item)  
{  
    struct node *ptr;  
       
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("OVERFLOW\n");  
        return;  
    }  
    else  
    {   
        
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = front;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next =front;  
        }  
    }  
}    


int delete ()  
{  
    struct node *ptr;  
    ptr=front;
    if((front == NULL) && (rear == NULL)) 
    {  
        printf("UNDERFLOW\n");  
    }  
    else if (front==rear)
    {

        front = rear =NULL;
        return ptr->data;
    }
    
    else   
    {  
        
        front = front -> next;  
        rear->next=front;
        return ptr->data; 
    }  
}




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


void pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    printf("%d\n",s->data[s->top--]);
}



int main()
{
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        insert(arr[i]);
    }
    Stack s;
    int k=0;
    init(&s);
    for(int i=0;i<n;i++)
    {
        k=delete();
        push(&s,k);   
    }
    printf("The Elements in reverse order \n");
    for(int i=0;i<n;i++)
    {
        pop(&s);
    }

    return 0;
}