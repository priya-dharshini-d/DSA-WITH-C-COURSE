// Program to implement iterative Binary Search


#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)         // Check if x is present at mid
            return mid;

        if (arr[mid] < x)          // If x greater, ignore left half
            low = mid + 1;

        else                       // If x is smaller, ignore right half
            high = mid - 1;
    }

    return -1;                     // If we reach here, then element was not present
}

// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
   if(result == -1) printf("Element is not present in array");
   else printf("Element is present at index %d",result);

}



//  Program to implement recursive Binary Search


#include <stdio.h>

// A recursive binary search function. It returns location of x in given array arr[low..high] is present, otherwise -1

int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2; // To avoid overflow

        if (arr[mid] == x)        // If the element is present at the middle itself
            return mid;

        if (arr[mid] > x)         // If element is smaller than mid, then it can only be present in left subarray
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);        // Else the element can only be present in right subarray
    }

    // We reach here when element is not present in array
    return -1;
}

// Driver code
int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d", result);
    return 0;
}


// Same code using else if and else


#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;  // Element found
        } else if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);  // Search in left half
        } else {
            return binarySearch(arr, mid + 1, high, x);  // Search in right half
        }
    }

    // Element not found
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        printf("Element is not present in array.\n");
    else
        printf("Element is present at index %d.\n", result);

    return 0;
}
