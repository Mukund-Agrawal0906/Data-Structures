#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}


int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}


void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}


void reverseQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }

    int data = dequeue(queue);
    reverseQueue(queue);
    enqueue(queue, data);
}


void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main() {
    struct Queue* queue = createQueue();
    int n=1;
    while(n){
        int a;
        printf("The Following Are Operation on queue\n");
        printf("1)Insert\n");
        printf("2)Display\n");
        printf("3)Exit\n");
        printf("Enter The Choice \n");
        scanf("%d",&a);
        switch(a){
            case 1:
            {
                int ab;
                printf("Enter the element \n");
                scanf("%d",&ab);
                enqueue(queue,ab);
                break;
            }

            case 2:
            {
                printf("Original Queue: ");
                printQueue(queue);
                printf("\n");
                reverseQueue(queue);
                printf("Reversed Queue: ");
                printQueue(queue);
                printf("\n");
                break;
            }

            case 3:
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
    return 0;
}