#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int FOUN;
    char location[50];
    int seatingCapacity;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(int FOUN, char location[], int seatingCapacity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->FOUN = FOUN;
    strcpy(newNode->location, location);
    newNode->seatingCapacity = seatingCapacity;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int FOUN, char location[], int seatingCapacity) {
    if (root == NULL)
        return createNode(FOUN, location, seatingCapacity);
    
    if (FOUN < root->FOUN)
        root->left = insertNode(root->left, FOUN, location, seatingCapacity);
    else if (FOUN > root->FOUN)
        root->right = insertNode(root->right, FOUN, location, seatingCapacity);
    else
        root->seatingCapacity = seatingCapacity;
    
    return root;
}

Node* searchNode(Node* root, int FOUN) {
    if (root == NULL || root->FOUN == FOUN)
        return root;
    
    if (FOUN < root->FOUN)
        return searchNode(root->left, FOUN);
    
    return searchNode(root->right, FOUN);
}

void displayInOrder(Node* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("\nFOUN: %d, Location: %s, Seating Capacity: %d\n", root->FOUN, root->location, root->seatingCapacity);
        displayInOrder(root->right);
    }
}
int findHeight(Node* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void printLowestLevelElements(Node* root, int level, int targetLevel) {
    if (root == NULL)
        return;
    
    if (level == targetLevel)
        printf("\nFOUN: %d, Location: %s, Seating Capacity: %d\n", root->FOUN, root->location, root->seatingCapacity);
    else {
        printLowestLevelElements(root->left, level + 1, targetLevel);
        printLowestLevelElements(root->right, level + 1, targetLevel);
    }
}

Node* findMinimum(Node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    
    return findMinimum(root->left);
}

Node* removeNode(Node* root, int FOUN) {
    if (root == NULL)
        return root;
    
    if (FOUN < root->FOUN)
        root->left = removeNode(root->left, FOUN);
    else if (FOUN > root->FOUN)
        root->right = removeNode(root->right, FOUN);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = findMinimum(root->right);
        root->FOUN = temp->FOUN;
        strcpy(root->location, temp->location);
        root->seatingCapacity = temp->seatingCapacity;
        root->right = removeNode(root->right, temp->FOUN);
    }
    
    return root;
}

int main() {
    Node* root = NULL;
    int choice, FOUN, seatingCapacity;
    char location[50];
    
    do {
        printf("\n--- Food Chain Franchise Management System ---\n");
        printf("1. Insert a Franchise Outlet\n");
        printf("2. Search for a Franchise Outlet\n");
        printf("3. Display All Franchise Outlets\n");
        printf("4. Display All Franchise Outlets at the lowest level\n");
        printf("5. Update Seating Capacity\n");
        printf("6. Remove a Franchise Outlet\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("\nExiting the program...\n");
                break;
            case 1:
                printf("\nEnter FOUN: ");
                scanf("%d", &FOUN);
                printf("\nEnter Location: ");
                scanf("%s", location);
                printf("\nEnter Seating Capacity: ");
                scanf("%d", &seatingCapacity);
                root = insertNode(root, FOUN, location, seatingCapacity);
                printf("\nFranchise Outlet added/updated successfully.\n");
                break;
            case 2:
                printf("\nEnter FOUN to search: ");
                scanf("%d", &FOUN);
                Node* searchResult = searchNode(root, FOUN);
                if (searchResult != NULL) {
                    printf("\nFOUN: %d, Location: %s, Seating Capacity: %d\n", searchResult->FOUN, searchResult->location, searchResult->seatingCapacity);
                } else {
                    printf("\nFranchise Outlet not found.\n");
                }
                break;
            case 3:
                printf("\nAll Franchise Outlets:\n");
                displayInOrder(root);
                break;
            case 4:
                printf("\nFranchise Outlets at the lowest level:\n");
                int lowestLevel = findHeight(root);

                printLowestLevelElements(root, 1, lowestLevel);
                break;
            case 5:
                printf("\nEnter FOUN to update seating capacity: ");
                scanf("%d", &FOUN);
                Node* updateResult = searchNode(root, FOUN);
                if (updateResult != NULL) {
                    printf("\nEnter new Seating Capacity: ");
                    scanf("%d", &seatingCapacity);
                    updateResult->seatingCapacity = seatingCapacity;
                    printf("\nSeating Capacity updated successfully.\n");
                } else {
                    printf("\nFranchise Outlet not found.\n");
                }
                break;
            case 6:
                printf("\nEnter FOUN to remove: ");
                scanf("%d", &FOUN);
                root = removeNode(root, FOUN);
                printf("\nFranchise Outlet removed successfully.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while (choice != 0);
    
    return 0;
}
