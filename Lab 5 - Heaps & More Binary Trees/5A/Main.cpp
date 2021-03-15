#include <random>
#include <windows.h>
#include "Heap.h"
#include "Heap.cpp"

double get_wall_time() {
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceFrequency(&freq)) {
        return 0;
    }
    if (!QueryPerformanceCounter(&time)) {
        return 0;
    }
    return static_cast<double>(time.QuadPart) / freq.QuadPart;
}

double get_cpu_time() {
    FILETIME a, b, c, d;
    if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
        return static_cast<double>(
            d.dwLowDateTime |
            (static_cast<unsigned long long>(d.dwHighDateTime) << 32)) *
            0.0000001;
    }
    return 0;
}

// Ryan Deering - X00144631
// Algorithms and Computation - Lab 5A

int main() {
    Heap<int> heap = Heap<int>();
    heap.insert(35);
    heap.insert(33);
    heap.insert(42);
    heap.insert(10);
    heap.insert(14);
    heap.insert(19);
    heap.insert(27);
    heap.insert(44);
    heap.insert(26);
    heap.insert(31);

    heap.display();
    std::cout << "Removing top element..." << std::endl;

    heap.remove();
    heap.display();

    std::cout << std::endl;
    std::cout << "Sorting..." << std::endl;

    heap.heapSort();

    heap.display();

    int randomNumber;
    Heap<int> heap2 = Heap<int>();
    for (int i = 0; i < 1000; i++) {
        randomNumber = (rand() % 1000) + 1;
        heap2.insert(randomNumber);
    }

    double HEAPSORTITRWALLbegin = get_wall_time();
    double HEAPSORTITRCPUbegin = get_cpu_time();

    heap2.heapSort();

    double HEAPSORTITRWALLend = get_wall_time();
    double HEAPSORTITRCPUend = get_cpu_time();

    double HEAPSORTITRWALLelapsed = HEAPSORTITRWALLend - HEAPSORTITRWALLbegin;
    double HEAPSORTITRCPUelapsed = HEAPSORTITRCPUend - HEAPSORTITRCPUbegin;
    std::cout << std::endl;

    std::cout << "Sorting 1000 ints..." << std::endl;
    std::cout << "Wall Time = " << std::fixed << HEAPSORTITRWALLelapsed
        << std::endl;
    std::cout << "CPU Time = " << std::fixed << HEAPSORTITRCPUelapsed
        << std::endl;

    int randomNumber2;
    Heap<int> heap3 = Heap<int>();
    for (int i = 0; i < 1000; i++) {
        randomNumber = (rand() % 1000) + 1;
        heap3.insert(randomNumber);
    }

    double HEAPSORTRECURWALLbegin = get_wall_time();
    double HEAPSORTRECURCPUbegin = get_cpu_time();

    heap3.heapSortRec();

    double HEAPSORTRECURWALLend = get_wall_time();
    double HEAPSORTRECURCPUend = get_cpu_time();

    double HEAPSORTRECURWALLelapsed =
        HEAPSORTRECURWALLend - HEAPSORTRECURWALLbegin;
    double HEAPSORTRECURCPUelapsed = HEAPSORTRECURCPUend - HEAPSORTRECURCPUbegin;
    std::cout << std::endl;

    std::cout << "Sorting 1000 ints...recursively" << std::endl;
    std::cout << "Wall Time = " << std::fixed << HEAPSORTRECURWALLelapsed
        << std::endl;
    std::cout << "CPU Time = " << std::fixed << HEAPSORTRECURCPUelapsed
        << std::endl;
    std::cout << std::endl;

    std::cout << "Recursive seems to perform better." << std::endl;
    std::cout << std::endl;

    std::cout << "Testing chars..." << std::endl;
    Heap<char> heap4 = Heap<char>();
    heap4.insert('A');
    heap4.insert('B');
    heap4.insert('C');
    heap4.insert('D');
    heap4.insert('E');
    heap4.insert('F');
    heap4.insert('G');
    heap4.insert('H');
    heap4.insert('I');
    heap4.insert('J');
    heap4.insert('K');

    std::cout << "Before sort" << std::endl;
    heap4.display();

    heap4.heapSortRec();
    std::cout << "After sort" << std::endl;
    heap4.display();
}
