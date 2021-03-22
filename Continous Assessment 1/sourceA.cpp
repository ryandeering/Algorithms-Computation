// AC-CA1.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//
//Ryan Deering

//Algorithms and Computation - CA1


#include <iostream>

template <typename T>
void quickSort(T[], int low, int high);

template <typename T>
int partition(T[], int low, int high);

// https://www.geeksforgeeks.org/quick-sort/
template <typename T>
int partition(T arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    // If current element is smaller than the pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// https://www.geeksforgeeks.org/quick-sort/
template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Comments to improve the quicksort algorithm:
// Use tail-call elimination to reduce the worst case space to O(log n)
// Essentially using a while loop so we only have to use one recursive call
// We could also reduce recurison depth by recursing only for the smaller of the
// partitions and using iteration to process the larger

// Ryan Deering

// Algorithms and Computation - CA1

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5, 69 };
    quickSort(arr, 0, 6);

    std::cout << "Sorted array INTS: " << std::endl;
    for (int i = 0; i <= 6; i++) {
        std::cout << arr[i] << std::endl;
    }

    double arr2[] = { 10.2, 7.3, 8.3, 9.2, 16.7, 55.2, 69.7 };
    quickSort(arr2, 0, 6);

    std::cout << "Sorted array DOUBLES: " << std::endl;
    for (int i = 0; i <= 6; i++) {
        std::cout << arr2[i] << std::endl;
    }
    return 0;
}
