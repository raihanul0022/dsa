#include <stdio.h>
#define MAX 50

typedef struct string
{
    char data[MAX];
    int lenght;
};

void create_string(struct string *s, char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        s->data[i] = str[i];
        i++;
    }
    s->data[i] = '\0';
    s->lenght = i;
}

void display(struct string *s)
{
    printf("%s\n", s->data);
}

int lenght(struct string *s)
{
    return s->lenght;
}

void concate(struct string *s1, struct string *s2)
{
    int j = 0;
    int i = s1->lenght;
    s1->data[i] = ' ';

    while (s2->data[j] != '\0')
    {
        s1->data[i + 1] = s2->data[j];
        i++;
        j++;
    }
    s1->data[i] = '\0';
}

int main()
{
    struct string s1;
    struct string s2;

    create_string(&s1, "SYLHET");
    create_string(&s2, "ENGINEERING COLLEGE");
    printf("String 1: ");
    display(&s1);
    printf("String 2: ");
    display(&s2);

    printf("Lenght of s1 is : %d\n", lenght(&s1));
    printf("Lenght of s2 is : %d\n", lenght(&s2));

    concate(&s1, &s2);
    printf("Concated string: ");
    display(&s1);

    return 0;
}