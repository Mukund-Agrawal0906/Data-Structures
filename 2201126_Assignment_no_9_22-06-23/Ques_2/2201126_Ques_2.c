#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else
    {
        struct Node *current = *root;
        while (1)
        {
            if (data < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = createNode(data);
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = createNode(data);
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
}

void heapify(struct Node *root)
{
    if (root == NULL)
        return;
    heapify(root->left);
    heapify(root->right);

    if (root->left && root->left->data < root->data)
    {
        swap(&root->left->data, &root->data);
    }
    if (root->right && root->right->data < root->data)
    {
        swap(&root->right->data, &root->data);
    }
}

void sortedInsert(int *arr, int *n, int data)
{
    int i = *n - 1;
    while (i >= 0 && arr[i] > data)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = data;
    (*n)++;
}

void extractMin(struct Node *root, int *arr, int *n)
{
    if (root == NULL)
        return;
    extractMin(root->left, arr, n);
    sortedInsert(arr, n, root->data);
    extractMin(root->right, arr, n);
}

void heapSort(struct Node **root)
{
    heapify(*root);
    int sortedArr[100];
    int n = 0;
    extractMin(*root, sortedArr, &n);

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");
}

int main()
{
    struct Node *root = NULL;


int n, data;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    if(n<1)
    {
        printf("Linked List Is empty \n");
        return 0;
    }

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    heapSort(&root);

    printf("Sorted list: \n");
    heapSort(&root);

    return 0;
}