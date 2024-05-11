#include<stdio.h>
#include<stdlib.h>
int counter=0;
int ind=0;

int BinarySearch(int arr[],int left, int right, int Target,int duplicate[], int size)
{
    if(right>=left)
    {
        int mid = left + (right-left)/2;

        if (arr[mid]==Target){
            duplicate[ind++]=mid;
            counter++;

            int l = mid - 1;
            int r = mid + 1;
            
            while (l >= 0 && arr[l] == Target)
            {
                duplicate[ind++] = l;
                counter++;
                l--;
            }

            while (r < size && arr[r] == Target)
            {
                duplicate[ind++] = r;
                counter++;
                r++;
            }

            return 0;
        }

        if (arr[mid]>Target)
            return BinarySearch(arr, left, mid-1,Target,duplicate, size);

        else
            return BinarySearch(arr, mid+1, right, Target,duplicate, size);

        
    }

    return -1;
}

int BinarySearchWithCount(int arr[], int size, int Target, int *count)
{
    int Duplicate[size]; 
    for(int k=0;k<size;k++)
    {
        Duplicate[k]=-1;
    }

    BinarySearch(arr, 0, size-1, Target, Duplicate, size);

    printf("The Index of Target Element in the sorted array is \n");
    

    if(counter==0)
    {
        printf("No Such Element found \n");
    }

    else
    {
        for(int i=0; i<counter;i++)
        {
            if(Duplicate[i]>-1)
            {
                printf("%d ",Duplicate[i]);
            }
        }
        printf("\nThe number of Target element is %d \n",counter);

    }

    return 0;
}

int main()
{
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);

    int Arr[n];
    printf("Enter the elements of non-decreasing sorted array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Arr[i]);
    }

    int target;
    printf("Enter the Target Element \n");
    scanf("%d",&target);

    BinarySearchWithCount(Arr, n, target, &counter);

    return 0;
}