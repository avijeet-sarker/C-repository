#include <stdio.h>
#include <stdlib.h>

void insertElement(int *arr, int *n, int pos, int val);
void deleteElement(int *arr, int *n, int pos);
int linearSearch(int *arr, int n, int key);
void traverse(int *arr, int n);

int main() {
    int n, choice, pos, val, key, index;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 10) * sizeof(int)); 

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insert element at specific position\n");
        printf("2. Delete element from specific position\n");
        printf("3. Linear search for an element\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertElement(arr, &n, pos, val);
                break;

            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                index = linearSearch(arr, n, key);
                if (index != -1)
                    printf("Element found at position %d\n", index);
                else
                    printf("Element not found\n");
                break;

            case 4:
                traverse(arr, n);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    free(arr);  
    return 0;
}


void insertElement(int *arr, int *n, int pos, int val) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
    printf("Element inserted.\n");
}


void deleteElement(int *arr, int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted.\n");
}


int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}


void traverse(int *arr, int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
