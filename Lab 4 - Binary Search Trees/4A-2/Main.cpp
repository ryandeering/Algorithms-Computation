#include <iostream>
#include "BST.h"

int main() {
  // Ryan Deering - X00144631
  // Algorithms and Computations - Lab 4B

  BST bst1;
  bst1.add('I');
  bst1.add('M');
  bst1.add('I');
  bst1.add('S');
  bst1.add('S');
  bst1.add('M');
  bst1.add('Y');
  bst1.add('W');
  bst1.add('I');
  bst1.add('F');
  bst1.add('E');

  std::cout << "Printing in ascending order..." << std::endl;
  bst1.printinAscOrder();

  std::cout << std::endl;

  std::cout << "Printing in pre order..." << std::endl;
  bst1.printPreOrder();

  std::cout << std::endl;

  std::cout << "Printing in post order..." << std::endl;
  bst1.printPostOrder();

  std::cout << std::endl;

  std::cout << "0 = false. 1 = true. Boolean values innit." << std::endl;

  std::cout << "Is the letter Q in the tree? " << bst1.search('Q') << std::endl;

  std::cout << "Is the letter W in the tree? " << bst1.search('W') << std::endl;
}