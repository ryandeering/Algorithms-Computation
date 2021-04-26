#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "HuffmanTree.h"

/*Algorithms & Computation CA2
 * Ryan Deering X00144631
 */
int main() {
    HuffmanTree* ht = new HuffmanTree();

    std::ifstream Input("Input.txt");
    std::stringstream ssStream;
    ssStream << Input.rdbuf();
    Input.close();
    std::string str = ssStream.str();

    std::cout << "Building frequency table..." << std::endl;
    std::map<char, int> mapping = ht->printCharacterFrequency(str);

    ht = ht->buildHuffmanTree(mapping);

    std::map<char, std::string> encodedTree;
    ht->encode(encodedTree);

    std::cout << "Built Huffman table..." << std::endl;
    for (auto& it : encodedTree) {
        std::cout << it.first << ' ' << it.second << '\n';
    }
    std::cout << "" << std::endl;

    std::ofstream encodedFile("Encoded.txt");

    for (int i = 0; i < str.length(); ++i) {
        encodedFile << encodedTree[str[i]];  // spitting out the appropriate binary
                                             // per character
    }
    std::cout << "" << std::endl;


    encodedFile.close();

    std::ifstream outputFile("Encoded.txt");
    std::stringstream ssStream2;
    ssStream2 << outputFile.rdbuf();
    encodedFile.close();
    std::string path = ssStream2.str();
    std::cout << "Decoding text..." << std::endl;
    ht->decode(ht, path);

    std::string compressed = ht->compress8BitChunk(path);

    std::ofstream compressedFile("Compressed.txt");

    compressedFile << compressed;

    compressedFile.close();

    // Input file size 218 bytes -> Compressed file size 118 bytes

    std::string decompressed = ht->decompress8BitChunk(compressed);

    std::ofstream decompressedFile("Decompressed.txt");

    decompressedFile << decompressed;

    decompressedFile.close();
    std::cout << "" << std::endl;
    std::cout << "Decoding compressed text: " << std::endl;

    ht->decode(ht, decompressed);

    return 0;
}