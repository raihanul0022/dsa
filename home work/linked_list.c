#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

Node *createNode(int input) {
    Node *nd = (Node *)malloc(sizeof(Node));

    if (nd == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    nd->value = input;
    nd->next = NULL;

    return nd;
}

LinkedList *createLinkedList() {
    LinkedList *ls = (LinkedList *)malloc(sizeof(LinkedList));

    if (ls == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;

    return ls;
}

void insert(int value, int position, LinkedList *ls) {

    if (position < 0 || position > ls->size) {
        printf("Invalid Position!\n");
        return;
    }

    Node *newNode = createNode(value);

    if (position == 0) {

        newNode->next = ls->head;
        ls->head = newNode;

        if (ls->size == 0)
            ls->tail = newNode;
    }

    else if (position == ls->size) {

        ls->tail->next = newNode;
        ls->tail = newNode;
    }

    else {

        Node *tmp = ls->head;

        for (int i = 0; i < position - 1; i++)
            tmp = tmp->next;

        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    ls->size++;
}

void show(LinkedList *ls) {

    if (ls->size == 0) {
        printf("Linked List is Empty\n");
        return;
    }

    Node *tmp = ls->head;

    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }

    printf("\n");
}

void deleteNode(int position, LinkedList *ls) {

    if (ls->size == 0) {
        printf("Linked List is Empty\n");
        return;
    }

    if (position < 0 || position >= ls->size) {
        printf("Invalid Position!\n");
        return;
    }

    if (position == 0) {

        Node *tmp = ls->head;
        ls->head = ls->head->next;

        if (ls->size == 1)
            ls->tail = NULL;

        free(tmp);
    }

    else {

        Node *tmp = ls->head;

        for (int i = 0; i < position - 1; i++)
            tmp = tmp->next;

        Node *toDelete = tmp->next;

        tmp->next = toDelete->next;

        if (position == ls->size - 1)
            ls->tail = tmp;

        free(toDelete);
    }

    ls->size--;
}

void isEmpty(LinkedList *ls) {

    if (ls->size == 0)
        printf("Linked List is Empty\n");
    else
        printf("Linked List is Not Empty\n");
}

void freeList(LinkedList *ls) {

    Node *current = ls->head;

    while (current != NULL) {

        Node *next = current->next;
        free(current);
        current = next;
    }

    free(ls);
}

int main() {

    LinkedList *ls = createLinkedList();

    insert(10, 0, ls);
    insert(20, 1, ls);
    insert(30, 2, ls);
    insert(15, 1, ls);

    printf("Linked List: ");
    show(ls);

    isEmpty(ls);

    deleteNode(0, ls);
    printf("Linked List after deleting node at first position: ");
    show(ls);
    deleteNode(ls->size - 1, ls);
    printf("Linked List after deleting node at last position: ");
    show(ls);
    deleteNode(1, ls);
    printf("Linked List after deleting node at position 2: ");
    show(ls);
    deleteNode(0, ls);
    printf("Linked List after deleting node at position 1: ");
    show(ls);

    isEmpty(ls);

    freeList(ls);

    return 0;
}