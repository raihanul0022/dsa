#include <stdio.h>
int main()
{
    char str[30], c;
    int count = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    
    for (c = 'a'; c <= 'z'; c++)
    {
        count = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == c)
                count++;
        }
        if (count > 0)
        {
            printf("Frequency of %c is: %d\n", c, count);
        }
    }
    return 0;
}