// linear search using iterative method

#include <stdio.h>

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = search(arr, N, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}



// Recursive method


#include <stdio.h>

int recursive_linear_search(int array[], int size, int target, int index) {
    // Base case: If we reach end of array
    if (index >= size)
        return -1;

    // If element is found
    if (array[index] == target)
        return index;

    // Recursive call
    return recursive_linear_search(array, size, target, index + 1);
}


int main() {
    int numbers[] = {2, 3, 4, 10, 40};
    int element_to_find = 10;
    int array_length = sizeof(numbers) / sizeof(numbers[0]);

    int result = recursive_linear_search(numbers, array_length, element_to_find, 0);

    if (result == -1)
        printf("Element is not present in the array.\n");
    else
        printf("Element is present at index %d.\n", result);

    return 0;
}
