#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int size;
    int* arr;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    else {
        stack->top++;
        stack->arr[stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    else {
        int value = stack->arr[stack->top];
        stack->top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}
int peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        printf("%d is at the top of the stack\n", stack->arr[stack->top]);
        return stack->arr[stack->top];
    }
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int main(){
    Stack* s1 = createStack(5);
    push(s1, 10);
    push(s1, 20);
    push(s1, 50);
    push(s1, 80);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);

    peek(s1);
    printf("Is stack empty? %s\n", isEmpty(s1) ? "Yes" : "No");
    return 0;
}