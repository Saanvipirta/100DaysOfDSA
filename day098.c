/*Write a C program to represent two polynomials using linked lists and perform their addition. Each node should store:

Coefficient
Exponent
Pointer to the next term

The program should display both input polynomials and their resultant polynomial after addition.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Insert a term at the end
void insert(struct Node **head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display polynomial
void display(struct Node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPolynomial(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {

        if (poly1->exp == poly2->exp) {
            insert(&result,
                   poly1->coeff + poly2->coeff,
                   poly1->exp);

            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        else if (poly1->exp > poly2->exp) {
            insert(&result,
                   poly1->coeff,
                   poly1->exp);

            poly1 = poly1->next;
        }

        else {
            insert(&result,
                   poly2->coeff,
                   poly2->exp);

            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main() {

    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;

    /* First Polynomial:
       5x^3 + 4x^2 + 2x + 7
    */

    insert(&poly1, 5, 3);
    insert(&poly1, 4, 2);
    insert(&poly1, 2, 1);
    insert(&poly1, 7, 0);

    /* Second Polynomial:
       3x^3 + 6x + 5
    */

    insert(&poly2, 3, 3);
    insert(&poly2, 6, 1);
    insert(&poly2, 5, 0);

    printf("First Polynomial:\n");
    display(poly1);

    printf("Second Polynomial:\n");
    display(poly2);

    result = addPolynomial(poly1, poly2);

    printf("Resultant Polynomial:\n");
    display(result);

    return 0;
}
