// Code 

#include <stdio.h>

void Merge(int A[], int temp[], int left, int mid, int right) {
    int i, left_end, size, temp_pos;

    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;

    // Merge the two halves into temp[]
    while (left <= left_end && mid <= right) {
        if (A[left] <= A[mid]) {
            temp[temp_pos++] = A[left++];
        } else {
            temp[temp_pos++] = A[mid++];
        }
    }

    // Copy remaining elements from left half (if any)
    while (left <= left_end) {
        temp[temp_pos++] = A[left++];
    }

    // Copy remaining elements from right half (if any)
    while (mid <= right) {
        temp[temp_pos++] = A[mid++];
    }

    // Copy temp[] back into A[]
    for (i = 0; i < size; i++, right--) {
        A[right] = temp[right];
    }
}

void Mergesort(int A[], int temp[], int left, int right) {
    int mid;
    if (right > left) {
        mid = (left + right) / 2;

        Mergesort(A, temp, left, mid);
        Mergesort(A, temp, mid + 1, right);

        Merge(A, temp, left, mid + 1, right);
    }
}


int main() {
    int A[] = {17, 26, 31, 44, 54, 55, 77, 93};
    int n = sizeof(A) / sizeof(A[0]);
    int temp[n];

    Mergesort(A, temp, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}


// Different coding style


#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for memcpy

// Utility to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}


/* ==========================================
   1. MergeSort using while loop (ascending)
   ========================================== */


void mergeSort1(int array[], int size) {
    if (size > 1) {
        int middle = size / 2;
        int leftSize = middle;
        int rightSize = size - middle;

        int* left = malloc(leftSize * sizeof(int));
        int* right = malloc(rightSize * sizeof(int));

        for (int i = 0; i < leftSize; i++) left[i] = array[i];
        for (int i = 0; i < rightSize; i++) right[i] = array[middle + i];

        mergeSort1(left, leftSize);
        mergeSort1(right, rightSize);

        int lp = 0, rp = 0, fp = 0;

        while (lp < leftSize && rp < rightSize) {
            if (left[lp] < right[rp]) array[fp++] = left[lp++];
            else array[fp++] = right[rp++];
        }

        while (lp < leftSize) array[fp++] = left[lp++];
        while (rp < rightSize) array[fp++] = right[rp++];

        free(left);
        free(right);
    }
}



/* ==========================================
   2. MergeSort using helper merge() (ascending)
   ========================================== */


void merge2(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort2(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort2(arr, left, mid);
        mergeSort2(arr, mid + 1, right);
        merge2(arr, left, mid, right);
    }
}




/* ==========================================
   3. MergeSort using while loop (descending)
   ========================================== */



void mergeSortDesc(int array[], int size) {
    if (size > 1) {
        int middle = size / 2;
        int leftSize = middle;
        int rightSize = size - middle;

        int* left = malloc(leftSize * sizeof(int));
        int* right = malloc(rightSize * sizeof(int));

        for (int i = 0; i < leftSize; i++) left[i] = array[i];
        for (int i = 0; i < rightSize; i++) right[i] = array[middle + i];

        mergeSortDesc(left, leftSize);
        mergeSortDesc(right, rightSize);

        int lp = 0, rp = 0, fp = 0;

        while (lp < leftSize && rp < rightSize) {
            if (left[lp] > right[rp]) array[fp++] = left[lp++];
            else array[fp++] = right[rp++];
        }

        while (lp < leftSize) array[fp++] = left[lp++];
        while (rp < rightSize) array[fp++] = right[rp++];

        free(left);
        free(right);
    }
}




/* ==========================================
   4. Iterative (Bottom-Up) Merge Sort
   ========================================== */



void mergeIter(int array[], int start, int middle, int end, int descending) {
    int left_size = middle - start + 1;
    int right_size = end - middle;

    int* left_half = malloc(left_size * sizeof(int));
    int* right_half = malloc(right_size * sizeof(int));

    for (int i = 0; i < left_size; i++) left_half[i] = array[start + i];
    for (int i = 0; i < right_size; i++) right_half[i] = array[middle + 1 + i];

    int il = 0, ir = 0, im = start;

    while (il < left_size && ir < right_size) {
        if ((left_half[il] <= right_half[ir]) ^ descending)
            array[im++] = left_half[il++];
        else
            array[im++] = right_half[ir++];
    }

    while (il < left_size) array[im++] = left_half[il++];
    while (ir < right_size) array[im++] = right_half[ir++];

    free(left_half);
    free(right_half);
}

void mergeSortIterative(int array[], int total_length, int descending) {
    int subarray_size = 1;

    while (subarray_size < total_length) {
        for (int left_start = 0; left_start < total_length; left_start += 2 * subarray_size) {
            int middle = left_start + subarray_size - 1;
            if (middle >= total_length) break;

            int right_end = left_start + 2 * subarray_size - 1;
            if (right_end >= total_length) right_end = total_length - 1;

            mergeIter(array, left_start, middle, right_end, descending);
        }
        subarray_size *= 2;
    }
}




/* ==========================================
   Main: Execute each version separately
   ========================================== */



int main() {
    // Version 1
    int arr1[] = {3, 2, 24, 27, 29, 31, 32};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int* temp1 = malloc(size1 * sizeof(int));
    memcpy(temp1, arr1, size1 * sizeof(int));
    mergeSort1(temp1, size1);
    printf("1. MergeSort (while, ascending): ");
    printArray(temp1, size1);
    free(temp1);

    // Version 2
    int arr2[] = {3, 2, 24, 27, 29, 31, 32};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    mergeSort2(arr2, 0, size2 - 1);
    printf("2. merge_sort (for+while, ascending): ");
    printArray(arr2, size2);

    // Version 3
    int arr3[] = {3, 2, 24, 27, 29, 31, 32};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    mergeSortDesc(arr3, size3);
    printf("3. MergeSort (while, descending): ");
    printArray(arr3, size3);

    // Version 4 - Ascending
    int arr4[] = {38, 27, 43, 3, 9, 82, 10};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    mergeSortIterative(arr4, size4, 0);
    printf("4. Iterative MergeSort (ascending): ");
    printArray(arr4, size4);

    // Version 4 - Descending
    int arr5[] = {38, 27, 43, 3, 9, 82, 10};
    mergeSortIterative(arr5, size4, 1);
    printf("   Iterative MergeSort (descending): ");
    printArray(arr5, size4);

    return 0;
}
