#include <stdio.h>
void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}
int main()
{
    int arr[] = {1, 6, 9, 245, 10};
    int size = 5;
    insertion_sort(arr, size);
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    return 0;
}