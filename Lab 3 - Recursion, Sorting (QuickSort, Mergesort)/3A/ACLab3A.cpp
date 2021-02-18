#include <iostream>
#include <vector>

int quickSortDivide(int* theArray, int size);
void quickSort(int* theArray, int size);
void mergeSort(int arrayToSort[], int startIndex, int lengthToSort);
void merge(int arraySortedInTwoHalves[], int startIndex, int length);
void swap(int& xp, int& yp);

//Ryan Deering X00144631 - Algorithms and Computation 
//Lab 3A


int main() {

    std::cout << "Printing initial array for Quicksort..." << std::endl;

    int arr[5] = { 4, 2, 0, 6, 9 };

    for (int i = 0; i <= 4; i++) {
        std::cout << arr[i] << std::endl;
    }
    quickSort(arr, 5);

    std::cout << "Printing sorted array for Quicksort..." << std::endl;

    for (int i = 0; i <= 4; i++) {
        std::cout << arr[i] << std::endl;
    }

    std::cout << "Printing initial array for Mergesort..." << std::endl;

    int array4[6] = { 12, 11, 13, 5, 6, 7 };

    for (int i = 0; i <= 5; i++) {
        std::cout << array4[i] << std::endl;
    }

    mergeSort(array4, 0, 5);

    std::cout << "Printing merged array for Mergesort..." << std::endl;

    for (int i = 0; i <= 5; i++) {
        std::cout << array4[i] << std::endl;
    }

    return 0;
}

//https://www.geeksforgeeks.org/merge-sort/
void merge(int arraySortedInTwoHalves[], int startIndex, int length) {
    int mid = ((startIndex + length) / 2); //https://www.mygreatlearning.com/blog/merge-sort/
    int left = mid - startIndex + 1;        //Pseudocode here really helped me understand the boundaries
    int right = length - mid;

    std::vector<int> leftArr(left);
    std::vector<int> rightArr(right);

    for (int i = 0; i < left; i++)
        leftArr[i] = arraySortedInTwoHalves[startIndex + i];
    for (int j = 0; j < right; j++)
        rightArr[j] = arraySortedInTwoHalves[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = startIndex;
    while (i < left && j < right) {
        if (leftArr[i] <= rightArr[j]) {
            arraySortedInTwoHalves[k] = leftArr[i];
            i++;
        }
        else {
            arraySortedInTwoHalves[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < left) {
        arraySortedInTwoHalves[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < right) {
        arraySortedInTwoHalves[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arrayToSort[], int startIndex, int lengthToSort) {
    if (startIndex < lengthToSort) {
        int mid = (startIndex + lengthToSort) / 2;
        mergeSort(arrayToSort, startIndex, mid);
        mergeSort(arrayToSort, mid + 1, lengthToSort);
        merge(arrayToSort, startIndex, lengthToSort);
    }
}

// https://www.geeksforgeeks.org/iterative-quick-sort/
int quickSortDivide(int* theArray, int size) {
    int pivot = theArray[size - 1];
    int i = -1;  // equivalent of  int i = (l - 1);

    for (int j = 0; j <= size - 1; j++) {
        if (theArray[j] < pivot) {
            i++;
            swap(theArray[i], theArray[j]);  // Note: I can pass without the & if I
                                             // have namespace std enabled....why?
        }
    }
    swap(theArray[i + 1], theArray[size - 1]);
    return (i + 1);
}

void quickSort(int* theArray, int size) {
    if (size > 0) {
        int mid = quickSortDivide(theArray, size);
        quickSort(theArray, mid);
        quickSort(&theArray[mid + 1], size - (mid + 1));

        // using array size rather than up down etc just means working out some
        // simple positions in the quickSortDivde function
        // assuming pivot as the last element
        // index of the first postion in the array
        // index of last pos before the pivot
        // now all you need to do is do the same for the recursive quicksort
        // function
    }
}

void swap(int& xp, int& yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}