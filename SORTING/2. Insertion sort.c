#include <stdio.h>

// ✅ Iterative Insertion Sort – Ascending Order

void insertion_sort_ascending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}



// ✅ Recursive Insertion Sort – Ascending Order


/*
✅ Recursive Insertion Sort Logic (Simplified)

Base Case:
If the array size is 1, it's already sorted. → So, do nothing and return.

Recursive Step:
Recursively sort the first size-1 elements of the array.

Insertion Step:
Take the last element and insert it into its correct position in the sorted part.
*/



void recursive_insertion_sort_ascending(int arr[], int size) {
    if (size <= 1) return;

    recursive_insertion_sort_ascending(arr, size - 1);

    int last = arr[size - 1];
    int j = size - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}




// ✅ Iterative Insertion Sort – Descending Order
void insertion_sort_descending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;

        // 🟢 Changed: use > instead of < for descending
        while (j >= 0 && current > arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}



// ✅ Recursive Insertion Sort – Descending Order
void recursive_insertion_sort_descending(int arr[], int size) {
    if (size <= 1) return;

    // Sort first size-1 elements
    recursive_insertion_sort_descending(arr, size - 1);

    int last = arr[size - 1];
    int j = size - 2;

    // 🟢 Changed: use < instead of > for descending
    while (j >= 0 && arr[j] < last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}





// Utility function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
int main() {
    int arr1[] = {12, 11, 13, 5, 6};
    int arr2[] = {12, 11, 13, 5, 6};
    int arr3[] = {12, 11, 13, 5, 6};
    int arr4[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    // Iterative Ascending
    printf("Input (Iterative Ascending): ");
    print_array(arr1, size);
    insertion_sort_ascending(arr1, size);
    printf("Output (Iterative Ascending): ");
    print_array(arr1, size);
    printf("\n");

    // Recursive Ascending
    printf("Input (Recursive Ascending): ");
    print_array(arr2, size);
    recursive_insertion_sort_ascending(arr2, size);
    printf("Output (Recursive Ascending): ");
    print_array(arr2, size);
    printf("\n");

    // Iterative Descending
    printf("Input (Iterative Descending): ");
    print_array(arr3, size);
    insertion_sort_descending(arr3, size);
    printf("Output (Iterative Descending): ");
    print_array(arr3, size);
    printf("\n");

    // Recursive Descending
    printf("Input (Recursive Descending): ");
    print_array(arr4, size);
    recursive_insertion_sort_descending(arr4, size);
    printf("Output (Recursive Descending): ");
    print_array(arr4, size);
    printf("\n");

    return 0;
}
