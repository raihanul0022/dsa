#include <stdio.h>
int search(int a[], int n)
{
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == n)
            return 1;
    }
    return -1;
}
int main()
{
    int n;
    int arr[10] = {3, 6, 1, 4, 8, 3, 2, 4, 6, 10};
    printf("Enter the value you want to search: ");
    scanf("%d", &n);
    if (search(arr, n) == 1)
        printf("Number found.");
    else
        printf("Number not found.");

    return 0;
}