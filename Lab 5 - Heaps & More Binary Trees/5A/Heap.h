#pragma once
#include <vector>

template <typename T>
class Heap {
public:
	Heap();
	void insert(T);
	void remove();
	void trickleUp();
	int getParentIndex(int nodeIndex);
	int getLeftChild(int parent);
	int getRightChild(int parent);
	void trickleDown();
	void display();
	void heapSort();
	void trickleDownJames(int size);
	void trickleDownRec(int size);
	void trickleUpRec(int size);
	void heapSortRec();

private:
	std::vector<T> h;
};
