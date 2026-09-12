// Recursive
#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; 
    }
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
    else {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
}

int main() {
    int arr[100];
    int n, target, temp;

    printf("How many numbers do you want to enter (Max 100)? ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf(" Please enter a size between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the number you want to find: ");
    scanf("%d", &target);
    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1) {
        printf(" Found %d at index %d in the sorted array.\n", target, result);
    } else {
        printf(" %d is not in the array.\n", target);
    }

    return 0;
}

