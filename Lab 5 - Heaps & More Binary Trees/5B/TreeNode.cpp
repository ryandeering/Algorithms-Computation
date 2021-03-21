#include "TreeNode.h"

TreeNode::TreeNode() {}

TreeNode::TreeNode(int dataIn) { data = dataIn; }

TreeNode::~TreeNode() {
	delete left;
	delete right;
}