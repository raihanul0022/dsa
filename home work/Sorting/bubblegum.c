#include <stdio.h>
void bubblesort(int arr[],int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted Array: ");
    for (int i = 0; i < 15; i++)
    {
        printf(" %d", arr[i]);
    }
}
int main()
{
    int arr[] = {1, 6, 9, 4, 10, 6, 8, 3, 2, 9, 7, 8, 12, 7, 15};
    int size = 15;
    bubblesort(arr,size);
    return 0;
}