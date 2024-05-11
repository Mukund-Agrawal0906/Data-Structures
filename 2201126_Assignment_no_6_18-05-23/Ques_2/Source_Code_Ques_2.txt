#include <stdio.h>
#include <stdlib.h>

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


int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


int hasDuplicates(struct Node* root) {
    if (root == NULL)
        return 0;
    

    if ((root->left != NULL && root->left->data == root->data) ||
        (root->right != NULL && root->right->data == root->data))
        return 1;
    

    return (hasDuplicates(root->left) || hasDuplicates(root->right));
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    do {
        printf("1. Insert node\n");
        printf("2. Get height of the tree\n");
        printf("3. Inorder traversal\n");
        printf("4. Preorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Check for duplicates\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Height of the tree: %d\n", getHeight(root));
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                if (hasDuplicates(root))
                    printf("The tree contains duplicate values.\n");
                else
                    printf("The tree does not contain duplicate values.\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    } while (choice != 7);
    
    return 0;
}
