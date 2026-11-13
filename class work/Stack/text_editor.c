#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} Stack;

Stack* create_stack(int size)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->size = size;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->size * sizeof(char));
    if (stack->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return stack;
}

void resize_stack(Stack* stack)
{
    stack->size *= 2;
    stack->arr = (char*)realloc(stack->arr, stack->size * sizeof(char));
    if (stack->arr == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
}

void push(Stack* stack, char value)
{
    if (stack->top == stack->size - 1) {
        resize_stack(stack);
    }
    stack->top++;
    stack->arr[stack->top] = value;
}


char pop(Stack* stack)
{
    if (stack->top == -1) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    char value = stack->arr[stack->top];
    stack->top--;
    return value;
}

int is_empty(Stack* stack)
{
    return stack->top == -1;
}

void clear_stack(Stack* stack)
{
    stack->top = -1;
}

void display(Stack* stack)
{
    if (stack->top == -1) {
        printf("Empty Stack");
        return;
    }
    printf("Stack Element: ");
    for (int i = 0; i <= stack->top; i++) {
        printf(" %c", stack->arr[i]);
    }
}

void free_stack(Stack* stack)
{
    free(stack->arr);
    free(stack);
}

int main()
{
    int choice;
    Stack* s1 = create_stack(5);   
    Stack* s2 = create_stack(5);   

    push(s1, 'a');
    push(s1, 'b');
    push(s1, 'c');
    push(s1, 'd');

    display(s1);

    printf("\n1- ctrl+z (undo)\n2- ctrl+y (redo)\n3- type new character\n");

    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input.");
            break;
        }

        if (choice == 1) {
            if (is_empty(s1)) {
                printf("\nNothing to undo.");
            } else {
                push(s2, pop(s1));
                display(s1);
            }
        }
        else if (choice == 2) {
            if (is_empty(s2)) {
                printf("\nNothing to redo.");
            } else {
                push(s1, pop(s2));
                display(s1);
            }
        }
        else if (choice == 3) {
            char c;
            printf("Enter character to type: ");
            scanf(" %c", &c);
            push(s1, c);
            clear_stack(s2);   
            display(s1);
        }
        else {
            printf("\nInvalid input.");
            break;
        }
    }

    free_stack(s1);
    free_stack(s2);
    return 0;
}
