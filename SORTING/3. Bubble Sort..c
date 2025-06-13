#include <stdio.h>
#include <stdbool.h>

// ------------------- Ascending Order -------------------



// 1. Using for loop alone
void bubbleSort_for(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++) { // Last i elements are already in place
            if (arr[j] > arr[j + 1]) {           // Swap if the element is greater than the next
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}



// 2. Using while loop alone
void bubbleSort_while(int arr[], int size) {
    bool swapped = true;
    int i = 0;
    while (swapped) {
        swapped = false;
        int j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
            j++;
        }
        i++;
    }
}



// 3. Using for and while loop
void bubbleSort_for_while(int arr[], int size) {
    int i = 0;
    while (i < size) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    }
}



// 4. For and while with swapped flag
void bubbleSort_for_while_optimized(int arr[], int size) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
    }
}



// 5. Recursive version
void bubbleSort_recursive(int arr[], int size) {
    if (size == 1) return;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSort_recursive(arr, size - 1);
}




// ------------------- Descending Order -------------------



// 1. For loop alone
void bubbleSort_for_desc(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}



// 2. While loop alone
void bubbleSort_while_desc(int arr[], int size) {
    bool swapped = true;
    int i = 0;
    while (swapped) {
        swapped = false;
        int j = 0;
        while (j < size - i - 1) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
            j++;
        }
        i++;
    }
}



// 3. For and while loop
void bubbleSort_for_while_desc(int arr[], int size) {
    int i = 0;
    while (i < size) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    }
}



// 4. For and while with swapped flag
void bubbleSort_for_while_optimized_desc(int arr[], int size) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
    }
}



// 5. Recursive version
void bubbleSort_recursive_desc(int arr[], int size) {
    if (size == 1) return;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSort_recursive_desc(arr, size - 1);
}



// ------------------- Utility Functions -------------------

// Utility Functions - "helper" functions—in this case, a function that performs a general-purpose task that can be reused.

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



// ------------------- Main Function to Test -------------------

int main() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort_for(arr1, size1);
    printf("Ascending (for loop only): ");
    printArray(arr1, size1);

    int arr2[] = {3, 0, 2, 5, -1, 4, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    bubbleSort_while(arr2, size2);
    printf("Ascending (while loop only): ");
    printArray(arr2, size2);

    int arr3[] = {7, 3, 8, 6, 2};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    bubbleSort_for_while(arr3, size3);
    printf("Ascending (for + while): ");
    printArray(arr3, size3);

    int arr4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    bubbleSort_for_while_optimized(arr4, size4);
    printf("Ascending (optimized): ");
    printArray(arr4, size4);

    int arr5[] = {10, 7, 3, 9, 2};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    bubbleSort_recursive(arr5, size5);
    printf("Ascending (recursive): ");
    printArray(arr5, size5);

    int arr6[] = {5, 2, 9, 1, 5, 6};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    bubbleSort_for_desc(arr6, size6);
    printf("Descending (for loop only): ");
    printArray(arr6, size6);

    int arr7[] = {3, 0, 2, 5, -1, 4, 1};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    bubbleSort_while_desc(arr7, size7);
    printf("Descending (while loop only): ");
    printArray(arr7, size7);

    int arr8[] = {7, 3, 8, 6, 2};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    bubbleSort_for_while_desc(arr8, size8);
    printf("Descending (for + while): ");
    printArray(arr8, size8);

    int arr9[] = {1, 2, 3, 4, 5};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    bubbleSort_for_while_optimized_desc(arr9, size9);
    printf("Descending (optimized): ");
    printArray(arr9, size9);

    int arr10[] = {10, 7, 3, 9, 2};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    bubbleSort_recursive_desc(arr10, size10);
    printf("Descending (recursive): ");
    printArray(arr10, size10);

    return 0;
}
