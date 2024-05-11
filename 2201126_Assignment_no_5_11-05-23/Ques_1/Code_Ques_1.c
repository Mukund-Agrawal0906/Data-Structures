#include<stdio.h>   
#include<stdlib.h>  

#define Max_Size 100

int count=0;

struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;  

void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("OVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("Enter The Element \n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            count++;
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            count++;
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("UNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
        count--;
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("Empty queue\n");  
    }  
    else  
    {   printf("printing values .....\n");  
        while(ptr != NULL)   
        {  
            printf("%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  

int main(){

    int n=1;
    while(n){
        int a;
        printf("The Following Are Operation on queue\n");
        printf("1)Insert\n");
        printf("2)Delete\n");
        printf("3)Display\n");
        printf("4)IsFull\n");
        printf("5)IsEmpty\n");
        printf("6)Exit\n");
        printf("Enter The Choice \n");
        scanf("%d",&a);
        switch(a){
            case 1:
            {
                insert();
                break;
            }

            case 2:
            {
                delete();
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                if(count==Max_Size-1){
                    printf("Yes\n");
                }
                else
                    printf("No\n");
                break;
            }

            case 5:
            {
                if(front==NULL){
                    printf("Yes\n");
                }
                else
                    printf("No\n");
                break;
            }

            case 6:
            {
                n=0;
                break;
            }
            
            default:
            {
                printf("Enter The Valid Choice\n");
                break;
            }

        }
    }
}