#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    int *arr;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

void push(Stack *stack, int value)
{
    if (stack->top == stack->size - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        stack->top++;
        stack->arr[stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int value = stack->arr[stack->top];
        stack->top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}
void display(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Empty stack");
        return;
    }
    else
    {
        printf("Stack Element: ");
        for (int i = 0; i <= stack->top; i++)
        {
            printf(" %d", stack->arr[i]);
        }

        printf("\nReverse Stack Element: ");
        for (int i = stack->top; i >= 0; i--)
        {
            printf(" %d", stack->arr[i]);
        }
    }
}

int main()
{
    Stack *s1 = createStack(5);

    push(s1, 12);
    push(s1, 26);
    push(s1, 31);
    push(s1, 41);
    push(s1, 58);


    display(s1);

    return 0;
}