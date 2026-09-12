// Iterative

#include <stdio.h>

int main() {
    int arr[100];
    int n, target, temp;
    int foundIndex = -1;
    printf("How many numbers do you want to enter (Max 100)? ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Please enter a size between 1 and 100.\n");
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
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            foundIndex = mid; 
            break;            
        }
        else if (arr[mid] < target) {
            low = mid + 1;    
        }
        else {
            high = mid - 1;   
        }
    }

    if (foundIndex != -1) {
        printf("  Found %d at index %d in the sorted array.\n", target, foundIndex);
    } else {
        printf(" %d is not in the array.\n", target);
    }

    return 0;
}
