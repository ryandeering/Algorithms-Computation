#include <iostream>
#include <vector>
#include "Heap.h"

template <typename T>
Heap<T>::Heap() = default;

template <typename T>
void Heap<T>::insert(T value) {
    h.push_back(value);  // doesn't a vector automatically grow when elements are
    // pushed onto it?
    trickleUp();
}

// https://www.youtube.com/watch?v=6i15PI_VP-E
template <typename T>
void Heap<T>::trickleUp() {
    int child = h.size() - 1;

    while (child > 0) {
        int parent = (child - 1) / 2;
        if (h[child] > h[parent]) {
            std::swap(h[child], h[parent]);
            child = parent;
        }
        else {
            break;
        }
        parent = getParentIndex(child);
    }
}

template <typename T>
int Heap<T>::getParentIndex(int nodeIndex) {
    if (nodeIndex % 2 == 0) return (nodeIndex / 2) - 1;
    return nodeIndex / 2;
}

template <class T>
int Heap<T>::getLeftChild(int parent) {
    return 2 * parent + 1;
}

template <class T>
int Heap<T>::getRightChild(int parent) {
    return 2 * parent + 2;
}

template <class T>
void Heap<T>::trickleDown() {
    int parent = 0;

    while (true) {
        int left = getLeftChild(parent);
        int right = getRightChild(parent);
        int length = h.size();
        int largest = parent;

        if (left < length && h[left] > h[largest]) largest = left;

        if (right < length && h[right] > h[largest]) largest = right;

        if (largest != parent) {
            std::swap(largest, parent);
            parent = largest;
        }
        else
            break;
    }
}

// different implementation of trickledown from James Lynam
template <class T>
void Heap<T>::trickleDownJames(int size) {
    int node = 0;
    // while the index of the node is less than the size of the heap
    while (node < size) {
        int lChildIndex = 2 * node + 1;
        int rChildIndex = 2 * node + 2;
        int swapIndex = -1;

        bool lChildRange = lChildIndex < size;
        bool rChildRange = rChildIndex < size;

        if ((lChildRange && rChildRange) &&
            (h[node] < h[lChildIndex] || h[node] < h[rChildIndex])) {
            // If children are present on both branches, swap the bigger one
            if (h[lChildIndex] < h[rChildIndex])
                swapIndex = rChildIndex;
            else
                swapIndex = lChildIndex;
        }
        else if (lChildRange && h[node] < h[lChildIndex]) {
            swapIndex = lChildIndex;
        }
        else if (rChildRange && h[node] < h[rChildIndex]) {
            swapIndex = rChildIndex;
        }
        else
            break;

        std::swap(h[node], h[swapIndex]);
        node = swapIndex;
    }
}

// https://www.geeksforgeeks.org/iterative-heap-sort/
// https://www.hackerearth.com/practice/algorithms/sorting/heap-sort/tutorial/
template <typename T>
void Heap<T>::heapSort() {
    int unsortedHeap = h.size();
    while (unsortedHeap > 0) {
        std::swap(h[0], h[unsortedHeap - 1]);
        --unsortedHeap;
        trickleDownJames(unsortedHeap);
    }
}

template <typename T>
void Heap<T>::heapSortRec() {
    int unsortedHeap = h.size();
    while (unsortedHeap > 0) {
        std::swap(h[0], h[unsortedHeap - 1]);
        --unsortedHeap;
        trickleDownRec(unsortedHeap);
    }
}

template <typename T>
void Heap<T>::remove() {
    int n = h.size();
    T last = h[n - 1];
    h.pop_back();
    h.erase(h.begin());
    h.push_back(last);
    trickleDown();
}

// I got this from a stackoverflow post but I don't remember which one, sorry
template <typename T>
void Heap<T>::display() {
    typename std::vector<T>::iterator pos = h.begin();
    std::cout << "Heap -->  ";
    while (pos != h.end()) {
        std::cout << *pos << " ";
        ++pos;
    }
    std::cout << std::endl;
}

// https://www.geeksforgeeks.org/heap-sort/
template <typename T>
void Heap<T>::trickleDownRec(int size) {
    // get left and right child of node at index `i`
    int left = getLeftChild(size);
    int right = getRightChild(size);

    int largest = size;

    // compare `A[i]` with its left and right child
    // and find the largest value
    if (left < h.size() && h[left] > h[size]) {
        largest = left;
    }

    if (right < h.size() && h[right] > h[largest]) {
        largest = right;
    }

    // swap with a child having greater value and
    // call heapify-down on the child
    if (largest != size) {
        std::swap(h[size], h[largest]);
        trickleDownRec(largest);
    }
}

template <typename T>
void Heap<T>::trickleUpRec(int size) {
    // check if the node at index `i` and its parent violate the heap property
    if (size && h[getParentIndex(size)] < h[size]) {
        // swap the two if heap property is violated
        std::swap(h[size], h[getParentIndex(size)]);

        // call heapify-up on the parent
        trickleUpRec(getParentIndex(size));
    }
}
