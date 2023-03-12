
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, max;
    for (i = 0; i < n-1; i++)
    {
        max = i;
        for (j = i+1; j < n; j++)
        if (arr[j] > arr[max])
            max = j;
        swap(&arr[max], &arr[i]);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size-1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[10],n; 
    printf("enter the number");
    scanf("%d",&n);
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
