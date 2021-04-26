#include "HuffmanNode.h"

HuffmanNode::HuffmanNode() = default;

HuffmanNode::HuffmanNode(char data, int weight) {
	character = data;
	freq = weight;
}

HuffmanNode::HuffmanNode(char data) {
	character = data;
	freq = 0;
}
