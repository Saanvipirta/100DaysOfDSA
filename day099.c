/* Write a C program to represent two Sparse Matrices using the 3-Tuple (Triplet) Representation and perform their addition.
A Sparse Matrix is a matrix in which most of the elements are zero. Instead of storing all elements, only non-zero elements along with their row and column indices are stored, making it memory-efficient. */
#include <stdio.h>

#define MAX 100

int main() {

    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];

    printf("\nEnter elements of First Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter elements of Second Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of matrices
    printf("\nResultant Matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Sparse Matrix Representation
    printf("\nTriplet Representation of Result Matrix:\n");
    printf("Row\tCol\tValue\n");

    int nonZero = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (result[i][j] != 0)
                nonZero++;
        }
    }

    printf("%d\t%d\t%d\n", rows, cols, nonZero);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (result[i][j] != 0) {
                printf("%d\t%d\t%d\n",
                       i, j, result[i][j]);
            }
        }
    }

    return 0;
}
