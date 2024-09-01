#include <stdio.h>

int iterativeBinarySearch(int arr[], int n, int search) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == search) {
            return mid;
        } else if (arr[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int n, i, search;
    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &search);
    int result = iterativeBinarySearch(arr, n, search);
    if (result != -1) {
        printf("Element found at position %d.\n", result + 1);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
