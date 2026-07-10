//Problem Statement :Write a C program to merge two already sorted arrays into a single sorted array without using any sorting algorithm.
#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter the size of first array: ");
    scanf("%d", &n1);

    int arr1[n1];

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter the size of second array: ");
    scanf("%d", &n2);

    int arr2[n2];

    printf("Enter elements of second array:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    while (i < n1)
        merged[k++] = arr1[i++];

    while (j < n2)
        merged[k++] = arr2[j++];

    printf("\nMerged Sorted Array:\n");
    for (i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);

    return 0;
}
