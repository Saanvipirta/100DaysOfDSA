//Write a C program to search for an element in a sorted array using the Binary Search algorithm.Binary Search repeatedly divides the search space in half, making it much faster than Linear Search for sorted data.
#include <stdio.h>

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the sorted elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int left = 0, right = n - 1;
    int found = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            found = mid;
            break;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if(found != -1)
        printf("Element found at index %d.\n", found);
    else
        printf("Element not found.\n");

    return 0;
}
