//Write a C program to check whether a given square matrix is symmetric. A matrix is symmetric if it is equal to its transpose, i.e., A[i][j] = A[j][i] for all elements.
#include <stdio.h>

int main() {
    int n;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int isSymmetric = 1;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n && isSymmetric; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    if (isSymmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}
