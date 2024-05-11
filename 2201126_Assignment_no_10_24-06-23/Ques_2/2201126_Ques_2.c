#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* mergeTwoLists(Node* l1, Node* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    Node* head = NULL;
    Node* tail = NULL;

    if (l1->data <= l2->data) {
        head = l1;
        tail = l1;
        l1 = l1->next;
    } else {
        head = l2;
        tail = l2;
        l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }

    if (l1 != NULL)
        tail->next = l1;
    if (l2 != NULL)
        tail->next = l2;

    return head;
}

Node* mergeKLists(Node** lists, int k) {
    if (k == 0)
        return NULL;

    int interval = 1;
    while (interval < k) {
        for (int i = 0; i + interval < k; i += interval * 2)
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        interval *= 2;
    }

    return lists[0];
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    int k;
    printf("Enter the number of linked lists (k): ");
    scanf("%d", &k);

    Node* lists[k];

    for (int i = 0; i < k; i++) {
        int n;
        printf("Enter the number of elements for list %d: ", i + 1);
        scanf("%d", &n);

        lists[i] = NULL;
        Node* tail = NULL;

        printf("Enter the sorted elements for list %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            int data;
            scanf("%d", &data);
            Node* newNode = createNode(data);

            if (lists[i] == NULL)
                lists[i] = newNode;
            else
                tail->next = newNode;
            tail = newNode;
        }
    }

    Node* mergedList = mergeKLists(lists, k);

    printf("Merged sorted list: ");
    printList(mergedList);

    freeList(mergedList);

    return 0;
}
