// Code 
// Hoare’s Partition Scheme (Ascending order)

#include <stdio.h>

// Swap function
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot_value = arr[low]; // Choose first element as pivot
    int start = low;
    int end = high;

    while (start < end) {
        // Move start index to the right while arr[start] <= pivot
        while (arr[start] <= pivot_value && start < high)
            start++;

        // Move end index to the left while arr[end] > pivot
        while (arr[end] > pivot_value)
            end--;

        // If indices haven't crossed, swap values
        if (start < end)
            swap(arr, start, end);
    }

    // Place the pivot element in its correct position
    swap(arr, low, end);  // arr[end] is now pivot's correct position
    return end;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}


// Hoare’s Partition Scheme (Descending order)

#include <stdio.h>

// Swap function
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int arr[], int low, int high) {  
    int pivot_value = arr[low]; // Choose first element as pivot
    int start = low;
    int end = high;

    while (start < end) {
        while (arr[start] >= pivot_value && start < high) // CHANGED
            start++;

        while (arr[end] < pivot_value) // CHANGED
            end--;

        if (start < end)
            swap(arr, start, end);
    }

    swap(arr, low, end);
    return end;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}


// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, size);

    quickSort(data, 0, size - 1);

    printf("Sorted array (Descending): ");
    printArray(data, size);

    return 0;
}






// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, size);

    quickSort(data, 0, size - 1);

    printf("Sorted array:   ");
    printArray(data, size);

    return 0;
}







#include <stdio.h>
#include <stdlib.h>

// Utility to print int arrays
void printArrayInt(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}



/*=======================================
  1. Recursive Algorithm (not stable)
=======================================*/

int* quick_sort_rec(int* arr, int size) {
    if (size <= 1) {
        int* out = malloc(size * sizeof(int));
        if (size == 1) out[0] = arr[0];
        return out;
    }
    int pivot = arr[0]; // Starting element as pivot

    int* left = malloc(size * sizeof(int));
    int* pivot_list = malloc(size * sizeof(int));
    int* right = malloc(size * sizeof(int));
    int li = 0, pli = 0, ri = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < pivot) left[li++] = arr[i];
        else if (arr[i] == pivot) pivot_list[pli++] = arr[i];
        else right[ri++] = arr[i];
    }

    int* L = quick_sort_rec(left, li);
    int* R = quick_sort_rec(right, ri);

    int* out = malloc(size * sizeof(int));
    int k = 0;
    for (int i = 0; i < li; i++) out[k++] = L[i];
    for (int i = 0; i < pli; i++) out[k++] = pivot_list[i];
    for (int i = 0; i < ri; i++) out[k++] = R[i];

    free(left); free(pivot_list); free(right);
    free(L); free(R);
    return out;
}



/*=======================================
  2. Lomuto Partition Scheme (Ascending)
=======================================*/


void swap(int arr[], int i, int j) {
    int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partition return index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}





/*=======================================
  3. Hoare’s Partition Scheme (Ascending)
=======================================*/
int partition_hoare(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start - 1, j = end + 1;
    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr, i, j);
    }
}

void quick_sort_hoare(int arr[], int start, int end) {
    if (start < end) {
        int pi = partition_hoare(arr, start, end);
        quick_sort_hoare(arr, start, pi);
        quick_sort_hoare(arr, pi + 1, end);
    }
}



/*=======================================
  4. Naive Partition Scheme (Ascending)
=======================================*/
void partition_naive(int arr[], int size) {
    int pivot = arr[size - 1];
    int* temp = malloc(size * sizeof(int));
    int idx = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] <= pivot) temp[idx++] = arr[i];
    for (int i = 0; i < size; i++)
        if (arr[i] > pivot) temp[idx++] = arr[i];
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
    free(temp);
}




/*=======================================
  5. Descending Recursive Algorithm
=======================================*/

int* quick_sort_desc(int* arr, int size) {
    if (size <= 1) {
        int* out = malloc(size * sizeof(int));
        if (size == 1) out[0] = arr[0];
        return out;
    }
    int pivot = arr[0];
    int* left = malloc(size * sizeof(int));
    int* pivot_list = malloc(size * sizeof(int));
    int* right = malloc(size * sizeof(int));
    int li = 0, pli = 0, ri = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > pivot) left[li++] = arr[i];
        else if (arr[i] == pivot) pivot_list[pli++] = arr[i];
        else right[ri++] = arr[i];
    }

    int* L = quick_sort_desc(left, li);
    int* R = quick_sort_desc(right, ri);

    int* out = malloc(size * sizeof(int));
    int k = 0;
    for (int i = 0; i < li; i++) out[k++] = L[i];
    for (int i = 0; i < pli; i++) out[k++] = pivot_list[i];
    for (int i = 0; i < ri; i++) out[k++] = R[i];

    free(left); free(pivot_list); free(right);
    free(L); free(R);
    return out;
}



/*=======================================
  6. Lomuto Partition - Descending
=======================================*/


int partition_lomuto_desc(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort_lomuto_desc(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_lomuto_desc(arr, low, high);
        quickSort_lomuto_desc(arr, low, pi - 1);
        quickSort_lomuto_desc(arr, pi + 1, high);
    }
}



/*===============================
  Main: Test each variant
===============================*/


int main() {
    int arr1[] = {10,7,8,9,1,5}, size1 = 6;
    int* out1 = quick_sort_rec(arr1, size1);
    printf("1 Rec Ascending: "); printArrayInt(out1, size1); free(out1);

    int arr2[] = {10,7,8,9,1,5}; quickSort(arr2, 0, size1-1);
    printf("2 Rec Lomuto Asc: "); printArrayInt(arr2, size1);

    int arr3[] = {10,7,8,9,1,5}; quick_sort_hoare(arr3, 0, size1-1);
    printf("3 Rec Hoare Asc: "); printArrayInt(arr3, size1);

    int arr4[] = {10,7,8,9,1,5}; partition_naive(arr4, size1);
    printf("4 Naive Asc: "); printArrayInt(arr4, size1);

    int arr5[] = {10,7,8,9,1,5}, *out5 = quick_sort_desc(arr5, size1);
    printf("5 Rec Desc: "); printArrayInt(out5, size1); free(out5);

    int arr6[] = {10,7,8,9,1,5}; quickSort_lomuto_desc(arr6, 0, size1-1);
    printf("6 Rec Lomuto Desc: "); printArrayInt(arr6, size1);

    return 0;
}
