#include <stdio.h>

int main() {
    int z, i, search, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &z);
    int arr[z];
    printf("Enter elements:\n");
    for (i = 0; i < z; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &search);
    for (i = 0; i < z; i++) {
        if (arr[i] == search) {
            found = 1;
            break;
        }
    }
    if (found)
        printf("%d found at position %d.\n", search, i + 1);
    else
        printf("%d not found.\n", search);

    return 0;
}
