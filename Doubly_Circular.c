#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


void insertAtStart(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

void insertAtPosition(int value, int position)
{
    if(position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(position == 1)
    {
        insertAtStart(value);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;

    for(int i=1;i<position-1;i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtStart()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *temp = head;

    head = head->next;

    head->prev = last;
    last->next = head;

    free(temp);
}

void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *last = head->prev;

    if(last == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);
}

void deleteAtPosition(int position)
{
    if(position < 1 || head == NULL)
    {
        printf("Invalid operation\n");
        return;
    }

    if(position == 1)
    {
        deleteAtStart();
        return;
    }

    struct Node *temp = head;

    for(int i=1;i<position;i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    if(head == NULL)
    {
        printf("Circular Doubly Linked List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Doubly Linked List: ");

    do{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("(back to head)\n");
}

int main()
{
    insertAtStart(10);
    insertAtStart(5);
    insertAtEnd(20);
    insertAtPosition(15,3);

    printf("After Insertion:\n");
    display();

    deleteAtStart();
    deleteAtEnd();
    deleteAtPosition(2);

    printf("\nAfter Deletion:\n");
    display();

    return 0;
}