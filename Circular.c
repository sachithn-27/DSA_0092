#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtStart(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;

    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
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
    temp->next = newNode;
}

void deleteAtStart()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if(head->next == head)
    {
        head = NULL;
        free(temp);
        return;
    }

    struct Node *last = head;

    while(last->next != head)
        last = last->next;

    head = head->next;
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

    struct Node *temp = head;
    struct Node *prev;

    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
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
    struct Node *prev;

    for(int i=1;i<position;i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

void display()
{
    if(head == NULL)
    {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    do{
        printf("%d -> ", temp->data);
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