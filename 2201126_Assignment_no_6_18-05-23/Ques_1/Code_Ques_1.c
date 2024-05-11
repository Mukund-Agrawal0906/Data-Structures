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
            rear -> next = front;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            count++;
            rear->next =front;  
        }  
    }  
}    


void delete ()  
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
        free(ptr);
        count--;
    }
    
    else   
    {  
        
        front = front -> next;  
        rear->next=front;
        free(ptr);  
        count--;
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if((front == NULL) && (rear == NULL))
    {  
        printf("Empty queue\n");  
    }  
    else  
    {   printf("printing values .....\n");  
        do
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        while(ptr!=front);
    }  
}  


void search(int item)
{
    struct node *ptr;
    ptr=front;
    if(front == NULL)  
    {  
        printf("Empty queue\n"); 
        printf("%d is not present \n",item); 
    }
    else
    {
        int n=0;
        do
        {
            if(ptr->data==item)
            {
                n=1;
            }
            ptr=ptr->next;
        } while (ptr!=front);
        
        if(n==1)
        {
            printf("%d is present \n",item);
        }
        else
        {
            printf("%d is not present \n",item); 
        }
    }
}


int main(){

    int n=1;
    while(n){
        int a;
        printf("The Following Are Operation on queue\n");
        printf("1)Insert\n");\
        printf("2)Delete\n");
        printf("3)Display\n");
        printf("4)IsFull\n");
        printf("5)IsEmpty\n");
        printf("6)Search\n");
        printf("7)Exit\n");
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
                int item;
                printf("Enter The element to be searched \n");
                scanf("%d",&item);
                search(item);
                break;
            }

            case 7:
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
