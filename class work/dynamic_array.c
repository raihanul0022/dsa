#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *arr;
    int sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        sum += arr[i];
    }

    average = (float)sum / n;

    printf("\nSum = %d\n", sum);
    printf("Average = %.2f\n", average);

    free(arr);

    return 0;
}