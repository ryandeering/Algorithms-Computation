#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <windows.h>
#include <stdio.h>
#include <chrono>
#define N 10000000
#define X 10000

int binarySearchIterative(const std::vector<int>& arr, int l, int r, int x);
template <typename T>
int binarySearchRecursive(const std::vector<T>& arr, int l, int r, int x);
int random(int min, int max);
void vectorInit(std::vector<int>& arr);
template <typename T>
T* quicksort(T* array, int start, int end);

//  Code is not portable. Written for Windows.
// https://stackoverflow.com/questions/17432502/how-can-i-measure-cpu-time-and-wall-clock-time-on-both-linux-windows
double get_wall_time()
{
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceFrequency(&freq)) {
        return 0;
    }
    if (!QueryPerformanceCounter(&time)) {
        return 0;
    }
    return (double)time.QuadPart / freq.QuadPart;
}
double get_cpu_time()
{
    FILETIME a, b, c, d;
    if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
        return (double)(d.dwLowDateTime | ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }
    else {
        return 0;
    }
}

//Ryan Deering - X00144631
//Algorithms and Computation - Lab 2B

int main()
{

    std::vector<int> arr;
    vectorInit(arr);

    double ItrArrayWALL[X];
    long long ItrArrayCPU[X];

    double ItrCPUbegin = get_cpu_time();
    for (size_t i = 0; i < X; i++) {
        double start_wallitr = get_wall_time();

        auto begin = std::chrono::high_resolution_clock::now();
        binarySearchIterative(arr, 0, N - 1, random(0, N));
        double end_wallitr = get_wall_time();
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        ItrArrayWALL[i] = end_wallitr - start_wallitr;
        ItrArrayCPU[i] = elapsed.count();
    }
    double ItrCPUend = get_cpu_time();

    double ItrCPU2 = ItrCPUend - ItrCPUbegin;

    double ItrWALL = 0.0;
    long long ItrCPU = 0;

    for (size_t i = 0; i < X; i++) {
        ItrWALL += ItrArrayWALL[i];
        ItrCPU += ItrArrayCPU[i];
    }

    std::cout << "Iterative Binary Search" << std::endl;
    std::cout << "Average Wall Time = " << std::fixed << ItrWALL / X << std::endl;
    std::cout << "Average CPU or Wall (Not sure which) Time for 10000 searches = " << std::fixed << ItrCPU / X << " nanoseconds" << std::endl;
    std::cout << "CPU Time for 10000 searches using Windows API = " << std::fixed << ItrCPU2 << "seconds" << std::endl;

    double RecurArrayWALL[X];
    long long RecurArrayCPU[X];

    double recCPUbegin = get_cpu_time();
    for (size_t i = 0; i < X; i++) {
        double start_wallrec = get_wall_time();
        auto beginrec = std::chrono::high_resolution_clock::now();
        binarySearchRecursive(arr, 0, N - 1, random(0, N));
        double end_wallrec = get_wall_time();
        auto endrec = std::chrono::high_resolution_clock::now();
        auto elapsedrec = std::chrono::duration_cast<std::chrono::nanoseconds>(endrec - beginrec);
        RecurArrayWALL[i] = end_wallrec - start_wallrec;
        RecurArrayCPU[i] = elapsedrec.count();
    }
    double recCPUend = get_cpu_time();

    double RecurWALL = 0.0;
    long long RecurCPU = 0;

    for (size_t i = 0; i < X; i++) {
        RecurWALL += RecurArrayWALL[i];
        RecurCPU += RecurArrayCPU[i];
    }
    double recurCPU2 = recCPUend - recCPUbegin;

    std::cout << "Recursive Binary Search" << std::endl;
    std::cout << "Average Wall Time = " << std::fixed << RecurWALL / X << std::endl;
    std::cout << "Average CPU or Wall (Not sure which) Time for 10000 searches = " << std::fixed << RecurCPU / X << " nanoseconds" << std::endl;
    std::cout << "CPU Time for 10000 searches using Windows API = " << std::fixed << recurCPU2 << "seconds" << std::endl;

    //quicksort(arr, 0, N - 1);
    //can't figure out requirements honestly...
    /* C++ no instance of function template matches the argument list
       argument types are : (std::vector<int, std::allocator<int>>, int, int)*/
       //I can't redesign it because of the requirement not to change the header.
       //But I don't think it's supposed to be executable in the first place.
       //I really have no idea.
}

//WITH WINDOWS API

//DEBUG:
//Iterative Binary Search
//Average Wall Time = 0.000000
//Average CPU or Wall(Not sure which) Time for 10000 searches = 104 nanoseconds
//CPU Time for 10000 searches using Windows API = 0.000000seconds
//Recursive Binary Search
//Average Wall Time = 0.000000
//Average CPU or Wall(Not sure which) Time for 10000 searches = 105 nanoseconds
//CPU Time for 10000 searches using Windows API = 0.000000seconds

//RELEASE:
//Iterative Binary Search
//Average Wall Time = 0.000002
//Average CPU or Wall(Not sure which) Time for 10000 searches = 1541 nanoseconds
//CPU Time for 10000 searches using Windows API = 0.031250seconds
//Recursive Binary Search
//Average Wall Time = 0.000002
//Average CPU or Wall(Not sure which) Time for 10000 searches = 2001 nanoseconds
//CPU Time for 10000 searches using Windows API = 0.015625seconds
//PS C : \Users\Ryan3\source\repos\ACLab2B\Debug >

//What does this tell us?
//In Release configuration, the two algorithms are basically the same in terms of performance.
//My THEORY is that the compiler in Release mode, does pre-determined optimisation to the code.
//In this case the calls of recursion are just transformed to loops.
//However, by default recursion is slower if the compiler is not optimised for this.
//I have no real proof of this aside from the results.

//https://softwareengineering.stackexchange.com/questions/273671/what-benefit-is-there-to-using-recursive-binary-search-over-iterative-binary-sea

//OLD RESULTS, COMMENTS ARE VALID THOUGH

//Document:
//
//The results are interesting. For reference, I tried the code, in both Debug and Release Mode, on different machines out of interest.
//
//I'll start with Debug:

//MODERN AMD RYZEN MACHINE:
//Iterative Binary Search
//Average Wall Time = 0.000001 seconds
//Average CPU Time for 10000 searches = 1446 nanoseconds
//Recursive Binary Search
//Average Wall Time = 0.000002 seconds
//Average CPU Time for 10000 searches = 1976 nanoseconds

//10 YEAR OLD THINKPAD:
//Iterative Binary Search
//Average Wall Time = 0.000002 seconds
//Average CPU Time for 10000 searches = 2123 nanoseconds
//Recursive Binary Search
//Average Wall Time = 0.000003 seconds
//Average CPU Time for 10000 searches = 2955 nanoseconds

//The implementation of the Iterative Binary Search seems to win on average compared to the Recursive one.
//At least on Debug mode.

//MODERN AMD RYZEN MACHINE:
//Iterative Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 102 nanoseconds
//Recursive Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 104 nanoseconds

//10 YEAR OLD THINKPAD:
//Iterative Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 126 nanoseconds
//Recursive Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 125 nanoseconds

//FRIEND'S GAMING LAPTOP (She could only run the release executable due to Visual C++ libraries not being installed.)
//Iterative Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 144 nanoseconds
//Recursive Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 155 nanoseconds

//OTHER FRIEND'S GAMER MACHINE (same thing with libraries)
//Iterative Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 99 nanoseconds
//Recursive Binary Search
//Average Wall Time = 0.000000 seconds
//Average CPU Time for 10000 searches = 99 nanoseconds

//What does this tell us?
//In Release configuration, the two algorithms are basically the same in terms of performance.
//My THEORY is that the compiler in Release mode, does pre-determined optimisation to the code.
//In this case the calls of recursion are just transformed to loops.
//However, by default recursion is slower if the compiler is not optimised for this.
//I have no real proof of this aside from the results.

//https://www.geeksforgeeks.org/binary-search/
int binarySearchIterative(const std::vector<int>& arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

//https://www.geeksforgeeks.org/binary-search/
template <typename T>
int binarySearchRecursive(const std::vector<T>& arr, int l, int r, int x)//Low to high boundaries and number to search.
{                                                                        // You COULD use vector.size but I just wanted to have a bit more portability.   
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearchRecursive(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearchRecursive(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

void vectorInit(std::vector<int>& arr)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(rand());
    }
}

//I forgot where I got this function from, sorry! I don't think it's hard to understand though.
int random(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

//swapping done in function

template <typename T>
int partition(T* array, int start, int end)
{
    T num = array[start];
    int i = start + 1;
    int j = end;
    T temp;

    while (1) {
        while (i < end && num > array[i])
            i++;
        while (num < array[j])
            j--;
        if (i < j) {
            temp = array[i];
            array[i] = array[j]; //swapping in function
            array[j] = temp;
        }
        else {
            temp = array[start];
            array[start] = array[j];
            array[j] = temp;
            return (j);
        }
    }
}

template <typename T>
T* quicksort(T* array, int start, int end)
{
    if (start < end) {
        int p = partition(array, start, end);
        // Separately sort elements before partition and after partition
        quicksort(array, start, p - 1);
        quicksort(array, p + 1, end);
    }
    return array;
}