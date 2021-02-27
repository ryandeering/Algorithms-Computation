#include <iostream>
#include <vector>
#include <windows.h>
#include <chrono>
int quickSortDivide(int* theArray, int size);
void quickSort(int* theArray, int size);
void mergeSort(int arrayToSort[], int startIndex, int lengthToSort);
void merge(int arraySortedInTwoHalves[], int startIndex, int length);
void swap(int& xp, int& yp);
void insertionSort(int arr[], int low, int n);

//  Code is not portable. Written for Windows.
// https://stackoverflow.com/questions/17432502/how-can-i-measure-cpu-time-and-wall-clock-time-on-both-linux-windows
double get_wall_time() {
  LARGE_INTEGER time, freq;
  if (!QueryPerformanceFrequency(&freq)) {
    return 0;
  }
  if (!QueryPerformanceCounter(&time)) {
    return 0;
  }
  return (double)time.QuadPart / freq.QuadPart;
}
double get_cpu_time() {
  FILETIME a, b, c, d;
  if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
    return (double)(d.dwLowDateTime |
                    ((unsigned long long)d.dwHighDateTime << 32)) *
           0.0000001;
  } else {
    return 0;
  }
}

// Ryan Deering X00144631 - Algorithms and Computation
// Lab 3B

int main() {
  const int X = 250000;
  const int Y = 100000;

  // I am so funny
  int* Xray = new int[X];

  for (int i = 0; i < X; i++) Xray[i] = rand() % 1000;

  double XWallbegin = get_wall_time();
  double XCPUbegin = get_cpu_time();

  quickSort(Xray, X);

  double XCPUend = get_cpu_time();
  double XWallend = get_wall_time();
  double XWallelapsed = XWallend - XWallbegin;
  double XCPUelapsed = XCPUend - XCPUbegin;

  std::cout << "Quicksort of 250000 random numbers" << std::endl;
  std::cout << "Wall Time = " << std::fixed << XWallelapsed << std::endl;
  std::cout << "CPU Time = " << std::fixed << XCPUelapsed << std::endl;

  int* Yray = new int[Y];

  for (int i = 0; i < Y; i++) Yray[i] = rand() % 1000;

  quickSort(Yray, Y);

  double YWallbegin = get_wall_time();
  double YCPUbegin = get_cpu_time();

  quickSort(Yray, Y);

  double YCPUend = get_cpu_time();
  double YWallend = get_wall_time();
  double YWallelapsed = YWallend - YWallbegin;
  double YCPUelapsed = YCPUend - YCPUbegin;

  std::cout << "Quicksort of 100000 pre-sorted numbers" << std::endl;
  std::cout << "Wall Time = " << std::fixed << YWallelapsed << std::endl;
  std::cout << "CPU Time = " << std::fixed << YCPUelapsed << std::endl;

  int* newray = new int[Y];

  for (int i = 0; i < Y; i++) newray[i] = rand() % 1000;

  optimisedquickSort(newray, Y);

  return 0;
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

int optimisedquickSortDivide(int* theArray, int size) {
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

void optimisedquickSort(int* theArray, int size) {
  while (size > 0) {
    int mid = optimisedquickSortDivide(theArray, size);

    int low = 0;

    if (size - low < 10) {
      insertionSort(theArray, low, size);
      break;
    } else {
      int mid = optimisedquickSortDivide(theArray, size);

      if (mid - low < size - mid) {
        optimisedquickSort(&theArray[low], size);
        low = mid + 1;
      } else {
        optimisedquickSort(&theArray[mid + 1], size);
        size = mid - 1;
      }
    }
  }
}

void insertionSort(int arr[], int low, int n) {
  // Start from the second element (the element at index 0
  // is already sorted)
  for (int i = low + 1; i <= n; i++) {
    int value = arr[i];
    int j = i;

    // find index `j` within the sorted subset `arr[0�i-1]`
    // where element `arr[i]` belongs
    while (j > low && arr[j - 1] > value) {
      arr[j] = arr[j - 1];
      j--;
    }

    // note that subarray `arr[j�i-1]` is shifted to
    // the right by one position, i.e., `arr[j+1�i]`

    arr[j] = value;
  }
}

void swap(int& xp, int& yp) {
  int temp = xp;
  xp = yp;
  yp = temp;
}