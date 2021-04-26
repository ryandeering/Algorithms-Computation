#pragma once
#include <map>

class Comparison;
class HuffmanTree;
class HuffmanNode {
public:
	HuffmanNode();
	HuffmanNode(char data);
	HuffmanNode(char data, int weight);
	HuffmanNode* createTree(const std::map<char, int>& freqTable);

private:
	HuffmanTree* left = nullptr;  // 0
	HuffmanTree* right = nullptr;  // 1
	char character;  // in-class initialization of the data members
	int freq = 0;
	friend class HuffmanTree;
};
