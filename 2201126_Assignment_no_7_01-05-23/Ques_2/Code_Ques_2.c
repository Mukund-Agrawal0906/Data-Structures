#include <stdio.h>
#include <stdlib.h>
int count=0;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    int sigma;
    printf("If You want to enter left type 1 and right right type 2\n");
    scanf("%d",&sigma);
    if (sigma==1)
        root->left = insertNode(root->left, data);
    else if (sigma==2)
        root->right = insertNode(root->right, data);
    else{
        printf("Enter the correct option\n");
    }
    return root;
}


void left_to_right(struct Node* root) {
    if (root == NULL)
        return;
  
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);
    
    left_to_right(root->left);
    left_to_right(root->right);
}


void right_to_left(struct Node* root) {
    if (root == NULL)
        return;
  
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

   right_to_left(root->right);
   right_to_left(root->left);
}


int main() {
    struct Node* root = NULL;
    int choice, data;
    int n=1;
    while (n) {
        printf("1. Insert node\n");
        printf("2. Operate the desired quest\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            {
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                count++;
                break;
            }
            
            case 2:
            {
                printf("\nLeft to right order printing ...\n");
                left_to_right(root);
                printf("\n");
                printf("\nRight to left order printing ...\n");
                right_to_left(root);
                printf("\n");
                printf("\nThe total number of nodes %d\n",count);
                break;
            }
            case 3:
                printf("Exiting...\n");
                n=0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
