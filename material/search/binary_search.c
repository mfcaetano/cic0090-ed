#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}//end binary_search


int main(){
    int numbers [] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};

    int numbers_size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 75;

    printf("%d - status: %s \n", target, (binary_search(numbers, numbers_size, target)) != -1 ? "found" : "not found"); 


}