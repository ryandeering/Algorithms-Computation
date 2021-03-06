#include "BST.h"
#include <iostream>
#include <windows.h>

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
    }
    else {
        return 0;
    }
}

// Ryan Deering - X00144631
// Algorithms and Computations - Lab 4B

int main() {


    BST bst1 = BST();

    bst1.add(6);
    bst1.add(4);
    bst1.add(8);
    bst1.add(3);
    bst1.add(5);
    bst1.add(7);
    bst1.add(9);

    std::cout << "BST Sum function returns 0 for false and 1 for true."
        << std::endl;
    std::cout << "Does the BST have a root-to-leaf sum of 15?: "
        << bst1.hasPathSum(15) << std::endl;
    std::cout << "Does the BST have a root-to-leaf sum of 30?: "
        << bst1.hasPathSum(42) << std::endl;
    std::cout << "Does the BST have a root-to-leaf sum of 21?: "
        << bst1.hasPathSum(21) << std::endl;
    std::cout << std::endl;

    std::cout << "Print paths....:" << std::endl;
    bst1.printPaths();

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Using pretty print, it's cooler!" << std::endl;
    std::cout << std::endl;
    bst1.pretty_print();
    std::cout << std::endl;

    std::cout << "Minimum Value of BST...: " << bst1.minValue() << std::endl;
    std::cout << "Maximum Value of BST...: " << bst1.maxValue() << std::endl;
    std::cout << std::endl;

    std::cout << "Height of BST: " << bst1.height() << std::endl;
    std::cout << std::endl;

    double BST1WALLbegin = get_wall_time();
    double BST1CPUbegin = get_cpu_time();
    std::cout << "Is this a BST? (Version 1) " << bst1.isBST() << std::endl;

    double BST1CPUend = get_cpu_time();
    double BST1WALLend = get_wall_time();
    double BST1WALLelapsed = BST1WALLend - BST1WALLbegin;
    double BST1CPUelapsed = BST1CPUend - BST1CPUbegin;

    std::cout << std::endl;

    std::cout << "BST1 function times" << std::endl;
    std::cout << "Wall Time = " << std::fixed << BST1WALLelapsed << std::endl;
    std::cout << "CPU Time = " << std::fixed << BST1CPUelapsed << std::endl;

    std::cout << std::endl;

    double BST2WALLbegin = get_wall_time();
    double BST2CPUbegin = get_cpu_time();
    std::cout << "Is this a BST? (Version 2) " << bst1.isBST2() << std::endl;

    double BST2CPUend = get_cpu_time();
    double BST2WALLend = get_wall_time();
    double BST2WALLelapsed = BST2WALLend - BST2WALLbegin;
    double BST2CPUelapsed = BST2CPUend - BST2CPUbegin;

    std::cout << std::endl;

    std::cout << "BST2 function times" << std::endl;
    std::cout << "Wall Time = " << std::fixed << BST2WALLelapsed << std::endl;
    std::cout << "CPU Time = " << std::fixed << BST2CPUelapsed << std::endl;
}
