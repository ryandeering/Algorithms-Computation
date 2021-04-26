#pragma once
#include <string>
#include "HuffmanNode.h"

class HuffmanTree {
public:
    HuffmanTree();
    HuffmanTree(int data, int weight);
    HuffmanTree(HuffmanTree* leftTree, HuffmanTree* rightTree, int totalWeight);
    std::map<char, int> printCharacterFrequency(std::string str);
    HuffmanTree* buildHuffmanTree(std::map<char, int> char_frequency);
    void encode(HuffmanNode* temp, std::string path,
        std::map<char, std::string>& encoded);
    void encode(std::map<char, std::string>& encoded);
    std::string decode(HuffmanTree* root, std::string s);
    std::string compress8BitChunk(std::string encodedString);
    std::string decompress8BitChunk(std::string compressedString);

private:
    HuffmanNode* root;
    int weight = -1;
    friend std::ostream& operator<<(std::ostream& out, const HuffmanTree& tree);
    friend class Comparison;
};

class Comparison {
public:
    bool operator()(const HuffmanTree* lhs, const HuffmanTree* rhs) const;
};