#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* getNode()
{
    return ((struct node*)malloc(sizeof(struct node)));
}

struct node * insertAtBeginning(int item, struct node *head)
{ 
    struct node *ptr = getNode();  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {
        if(head->data==0)  
        {  
            ptr->next = NULL;  
            ptr->prev=NULL;  
            ptr->data=item;  
            head=ptr;  
        }  
        else   
        {  
            ptr->data=item;  
            ptr->prev=NULL;  
            ptr->next = head;  
            head->prev=ptr;  
            head=ptr;  
        }  
    }
    return head;
}

struct node * insertAtEnd(int item, struct node *head)
{
    struct node * newNode;
    struct node * last;
    last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = getNode();

        newNode->data = item;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;
    }
    return head;
}

struct node * insertAtN(int data, int position,struct node * head)
{
    int i;
    struct node * newNode, *temp;
    struct node * last;
    last=head;

    while(last->next!=NULL)
    {
        last=last->next;
    }

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data,head);
        }
        else if(temp == last)
        {
            insertAtEnd(data,head);
        }
        else if(temp!=NULL)
        {
            newNode = getNode();

            newNode->data = data;
            newNode->next = temp->next; 
            newNode->prev = temp;          

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;
            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position+1);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
    return head;
}

struct node * deletion_beginning(struct node * head)  
{  
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nNode Deleted\n");  
    }  
    else  
    {  
        temp=head;    
        head = temp -> next;
        head->prev=NULL;
        free(temp); 
        printf("\nNode Deleted\n");  
    }  
    return head;
}

struct node * Deletion_Last(struct node * head)
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }
    return head;  
}  

struct node * Deletion_atSpecified(struct node *head,int position)
{  
    int i;
    struct node * ptr, *temp;
    struct node * last;
    last=head;

    while(last->next!=NULL)
    {
        last=last->next;
    }

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            deletion_beginning(head);
        }
        else if(temp == last)
        {
           Deletion_Last(head);
        }
        else if(temp!=NULL)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
    return head;
}  

struct node * print(struct node * head)
{
    struct node * ptr;
    struct node * ptr2;
    ptr=head;
    ptr2=head;
    while(ptr2->next!=NULL)
    {
        ptr2=ptr2->next;
    }
    
    if (head==NULL){
        printf("The list is empty\n");
    }
    else if (head->next==NULL)
    {
        printf("Element : %d\n",head->data);
        printf("List contains only one element \n");
    }
    else 
    {
        printf("Elements in Forward order \n");
        while (ptr!=NULL)
        {
            printf("Element: %d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("Elements in Backward order \n");
        while (ptr2!=NULL)
        {
            printf("Element: %d\n",ptr2->data);
            ptr2=ptr2->prev;
        }

    }
    return head;
}

int main()
{
    int n=1;
    struct node *head=getNode();
    head->next=NULL;
    head->prev=NULL;
    head->data=0;
    while(n){
        int a;
        printf("Enter the operation No. from Menu-Driven \n");
        printf("1) Insert an element at the beginning of the list. \n");
        printf("2) Insert an element at the end of the list. \n");
        printf("3) Insert an element at a specified position in the list. \n");
        printf("4) Delete an element from the beginning of the list. \n");
        printf("5) Delete an element from the end of the list. \n");
        printf("6) Delete an element from a specified position in the list. \n");
        printf("7) Print the contents of the list in forward and backward order. \n");
        printf("8) Exit \n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
        {
            int data;
            printf("Enter the element \n");
            scanf("%d",&data);
            head=insertAtBeginning(data,head);
            break;
        }
        case 2:
        {
            int data1;
            printf("Enter the element \n");
            scanf("%d",&data1);
            head=insertAtEnd(data1,head);
            break;
        }
        case 3:
        {
            int data2;
            int position;
            printf("Enter the element \n");
            scanf("%d",&data2);
            printf("Enter the position after which you have to insert \n");
            scanf("%d",&position);
            head=insertAtN(data2,position,head);
            break;
        }
        case 4:
        {
            head=deletion_beginning(head);
            break;
        }
        case 5:
        {
            head=Deletion_Last(head);
            break;
        }
        case 6:
        {
            int position1;
            printf("Enter the position which you have to delete \n");
            scanf("%d",&position1);
            head=Deletion_atSpecified(head,position1);
        }
        case 7:
        {
            head=print(head);
            break;
        }
        case 8:
        {
            n=0;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
