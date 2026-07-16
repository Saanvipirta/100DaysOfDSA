/*Write a C program to implement a Stack using Linked Lists. The program should support the following operations:

Push (Insert an element)
Pop (Remove the top element)
Peek (Display the top element)
Display all elements
Exit

Unlike stacks implemented using arrays, a stack using linked lists does not have a fixed size and can grow dynamically as memory permits.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push Operation
void push(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed successfully.\n", value);
}

// Pop Operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;
    printf("%d popped successfully.\n", top->data);

    top = top->next;
    free(temp);
}

// Peek Operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element is: %d\n", top->data);
}

// Display Operation
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("Stack Elements (Top to Bottom): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n------ Stack Menu ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
