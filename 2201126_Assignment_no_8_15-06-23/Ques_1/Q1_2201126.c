
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void counter(int array[],int size){
    int c1=0,c2=0,c3=0,c4=0;
    for (int i=0;i<size;i++){
        if(array[i]==1)
            c1++;
        if(array[i]==2)
            c2++;
        if(array[i]==4)
            c3++;
        if(array[i]==8)
            c4++;
    }
    printf("Number of students in \n");
    printf("Ritchie is %d\n",c1);
    printf("Babbage is %d\n",c2);
    printf("Turing is %d\n",c3);
    printf("Dijkstra is %d\n",c4);
}

int main()
{
    int n;
    printf("Enter the number of students \n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the house-id's for %d students according to: \n",n);
    printf("1-Ritchie\n");
    printf("2-Babbage\n");
    printf("4-Turing\n");
    printf("8-Dijkstra\n");

    for(int i=0;i<n;){
        int a=0;
        scanf("%d",&a);
        if(a==1 || a==2 || a==4 || a==8){
            arr[i++]=a;
        }
        else{
            printf("Invalid-id please enter again \n");
        }
    }
    

    
    quickSort(arr, 0, n - 1);

    printf("Sorted array according to house id's: \n");
    printArray(arr, n);

    counter(arr,n);

    return 0;
}