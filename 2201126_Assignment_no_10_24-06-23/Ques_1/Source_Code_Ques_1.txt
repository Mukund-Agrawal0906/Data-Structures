#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50


struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    int salary;
};

void insertionSort(struct Record arr[], int n, int sortField) {
    int i, j;
    struct Record key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && (
            (sortField == 1 && strcmp(arr[j].name, key.name) > 0) ||
            (sortField == 2 && arr[j].age > key.age) ||
            (sortField == 3 && arr[j].salary > key.salary)
        )) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(struct Record arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("Name: %s, Age: %d, Salary: %d\n", arr[i].name, arr[i].age, arr[i].salary);
    printf("\n");
}

int main() {
    int i, n, sortField;
    struct Record *records;

    printf("Enter the number of records: ");
    scanf("%d", &n);

    records = (struct Record *)malloc(n * sizeof(struct Record));


    for (i = 0; i < n; i++) {
        printf("Record %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", records[i].name);
        printf("Enter age: ");
        scanf("%d", &records[i].age);
        printf("Enter salary: ");
        scanf("%d", &records[i].salary);
    }

    printf("\nOriginal array:\n");
    printArray(records, n);

    printf("Choose a field to sort by:\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("3. Salary\n");
    printf("Enter your choice: ");
    scanf("%d", &sortField);

    insertionSort(records, n, sortField);

    printf("\nSorted array:\n");
    printArray(records, n);

    free(records);
    return 0;
}
