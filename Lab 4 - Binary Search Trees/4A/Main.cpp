#include "BST.h"
#include <iostream>

int main() {
  // Ryan Deering - X00144631
  // Algorithms and Computations - Lab 4B

  BST bst1 = BST();

  bst1.add(1);
  bst1.add(2);
  bst1.add(3);
  bst1.add(4);
  bst1.add(5);

  std::cout << bst1.height() << std::endl;

  // bst1.remove(2);

  std::cout << bst1.height() << std::endl;
}
