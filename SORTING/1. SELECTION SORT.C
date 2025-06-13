#include <stdio.h>


// ✅ Iterative Selection Sort (Unstable)

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (i != min_index) {  // ✅ Only swap when needed
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}


// ✅ Stable Selection Sort (Iterative)

void stable_selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int min_value = arr[min_index];

            for (int k = min_index; k > i; k--) {
                arr[k] = arr[k - 1];
            }

            arr[i] = min_value;
        }
    }
}

/*
🔍 Step-by-step example for stable sort:
Initial: [4a, 2a, 3, 2b, 1]

Pass 1: Min = 1 → insert at index 0, shift everything
→ [1, 4a, 2a, 3, 2b]

Pass 2: Min = 2a → insert at index 1, shift
→ [1, 2a, 4a, 3, 2b]

Pass 3: Min = 2b → insert at index 2, shift
→ [1, 2a, 2b, 4a, 3]

Pass 4: Min = 3 → insert at index 3
→ [1, 2a, 2b, 3, 4a]
*/


// ✅ Recursive Selection Sort (Unstable)
void selection_sort_recursive(int arr[], int size, int index) {
    if (index >= size - 1) return;

    int min_index = index;
    for (int j = index + 1; j < size; j++) {
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }

    if (min_index != index) {
        int temp = arr[index];
        arr[index] = arr[min_index];
        arr[min_index] = temp;
    }

    selection_sort_recursive(arr, size, index + 1);
}


// ✅ Recursive Selection Sort (Stable)
void stable_selection_sort_recursive(int arr[], int size, int start) {
    if (start >= size - 1) return;

    int min_index = start;
    for (int i = start + 1; i < size; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    if (min_index != start) {
        int min_value = arr[min_index];

        for (int k = min_index; k > start; k--) {
            arr[k] = arr[k - 1];
        }

        arr[start] = min_value;
    }

    stable_selection_sort_recursive(arr, size, start + 1);
}



// Utility to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr1[] = {4, 2, 3, 2, 1};
    int arr2[] = {4, 2, 3, 2, 1};
    int arr3[] = {4, 2, 3, 2, 1};
    int arr4[] = {4, 2, 3, 2, 1};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    printf("Input (Unstable Iterative): ");
    print_array(arr1, size);
    selection_sort(arr1, size);
    printf("Output (Unstable Iterative): ");
    print_array(arr1, size);
    printf("\n");

    printf("Input (Stable Iterative): ");
    print_array(arr2, size);
    stable_selection_sort(arr2, size);
    printf("Output (Stable Iterative): ");
    print_array(arr2, size);
    printf("\n");

    printf("Input (Unstable Recursive): ");
    print_array(arr3, size);
    selection_sort_recursive(arr3, size, 0);
    printf("Output (Unstable Recursive): ");
    print_array(arr3, size);
    printf("\n");

    printf("Input (Stable Recursive): ");
    print_array(arr4, size);
    stable_selection_sort_recursive(arr4, size, 0);
    printf("Output (Stable Recursive): ");
    print_array(arr4, size);
    printf("\n");

    return 0;
}
