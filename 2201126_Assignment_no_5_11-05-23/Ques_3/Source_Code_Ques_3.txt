#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int element) {
    if (rear == MAX_SIZE) {
        printf("Queue is full\n");
    } else {
        queue[rear++] = element;
    }
}

int dequeue() {
    if (front == rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void remove_element(int k) {
    int temp_rear = rear;
    int temp_element;
    
    while (front != temp_rear) {
        temp_element = dequeue();
        if (temp_element != k) {
            enqueue(temp_element);
        }
    }
}

int main() {
    int n,k;
    printf("Enter The Number of Elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter The Element You Want Delete \n");
    scanf("%d",&k);
    
    
    for (int i = 0; i < n; i++) {
        enqueue(arr[i]);
    }
    
    
    remove_element(k);
    
    
    while (front != rear) {
        printf("%d ", dequeue());
    }
    printf("\n");
    
    return 0;
}
