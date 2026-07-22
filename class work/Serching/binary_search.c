#include <stdio.h>
int binary_search(int arr[], int low, int high, int value)
{
    int mid = (high + low) / 2;
    if (low <= high)
    {
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            return binary_search(arr, low, mid - 1, value);
        else if (arr[mid] < value)
            return binary_search(arr, mid + 1, high, value);
    }
    return -1;
}
int main()
{
    int value;
    int arr[] = {2, 5, 9, 10, 25, 46, 55, 59, 62, 79, 84, 98};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the value you want to find: ");
    scanf("%d", &value);
    if (binary_search(arr, 0, size - 1, value) == -1)
        printf("%d is not found in the array.", value);
    else
        printf("%d is found at index: %d", value, binary_search(arr, 0, size - 1, value));
    return 0;
}