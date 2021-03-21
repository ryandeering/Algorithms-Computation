#include "BST.h"
#include <iostream>

int main() {
    // Ryan Deering - X00144631
    // Algorithms and Computations - Lab 5B

    std::string filepath = "bst.txt";
    std::ofstream outstream(filepath);
    std::ifstream instream(filepath);
    std::ofstream outstream2("bst2.txt");

    BST bst1 = BST();

    bst1.add(7);
    bst1.add(6566);
    bst1.add(122);
    bst1.add(33);
    bst1.add(4);
    bst1.add(7);
    bst1.add(66);
    bst1.add(12);
    bst1.add(33);
    bst1.add(22);

    std::cout << bst1.height() << std::endl;

    bst1.pretty_print();

    std::cout << std::endl;
    std::cout << "Did writing to file succeed? 1 for yes -1 for no.....RESULT: "
        << bst1.Serialise(outstream) << std::endl;
    std::cout << "Height: " << bst1.height() << std::endl;

    std::cout << std::endl;
    std::cout << "New BST generated from deserialized file." << std::endl;
    BST bst2 = BST();
    std::cout << "Did reading from file succeed? 1 for yes -1 for no.....RESULT: "
        << bst2.Deserialise(instream) << std::endl;
    std::cout << "Height should be 6...." << std::endl;
    std::cout << "Height: " << bst2.height() << std::endl;

    bst2.Serialise(outstream2);  // produces same file
    std::cout << std::endl;
    bst2.pretty_print();

    std::cout << std::endl;
    std::cout << "C++ file reading is a lot less nightmarish than Java."
        << std::endl;
}