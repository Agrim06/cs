#include <stdio.h>
#include <stdlib.h>

int *arr;
int n = 0;        
int capacity;    

void insertByPosition() {
    int pos, value;

    if (n == capacity) {
        capacity *= 2;
        arr = (int *)realloc(arr, capacity * sizeof(int));
        if (arr == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }

    printf("Enter position (0 to %d) and value: ", n);
    scanf("%d %d", &pos, &value);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;
}
void deleteByKey() {
    int key, found = 0;

    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            n--;
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Key not found!\n");
}
void searchByPosition() {
    int pos;

    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Element at position %d is %d\n", pos, arr[pos]);
}
void reverseArray() {
    int temp;

    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    printf("Array reversed successfully.\n");
}
void display() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;

    printf("Enter initial capacity of array: ");
    scanf("%d", &capacity);

    arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n========= ARRAY MENU =========\n");
        printf("1. Insert by Position\n");
        printf("2. Delete by Key\n");
        printf("3. Search by Position\n");
        printf("4. Reverse the Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertByPosition();
                display();
                break;
            case 2:
                deleteByKey();
                display();
                break;
            case 3:
                searchByPosition();
                break;
            case 4:
                reverseArray();
                display();
                break;
            case 0:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    free(arr);
    return 0;
}
