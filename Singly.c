#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtStart(int value)
 {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int value, int position)
 {
    if (position < 1) {
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
{
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
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
    free(temp);
}

void deleteAtEnd()
 {
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) 
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
     {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position) 
{
    if (head == NULL || position < 1) 
    {
        printf("Invalid operation\n");
        return;
    }

    if (position == 1)
     {
        deleteAtStart();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < position - 1 && temp->next != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp->next == NULL) 
    {
        printf("Position out of range\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void display()
 {
    struct Node *temp = head;

    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
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

    display();
    
    deleteAtStart();
    deleteAtEnd();
    deleteAtPosition(2);

    display();

    return 0;
}