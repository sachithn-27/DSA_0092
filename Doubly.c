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
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtEnd(int value)
 {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
     {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int value, int position) 
{

    if (position < 1) 
{
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
     {
        insertAtStart(value);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
     {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteAtStart() 
{
    if (head == NULL)
     {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteAtEnd() 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteAtPosition(int position)
 {
    if (head == NULL || position < 1) 
    {
        printf("Invalid operation\n");
        return;
    }

    struct Node *temp = head;

    if (position == 1)
     {
        deleteAtStart();
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
     {
        printf("Position out of range\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() 
{

    struct Node *temp = head;

    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
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
    printf("After Deletion:\n");
    display();

    return 0;
}