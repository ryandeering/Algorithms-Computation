#pragma once
#include "TreeNode.h"
#include <string>
class BST {
	friend class TreeNode;

public:
	void pretty_print();
	BST();
	~BST();
	void DestroyRecursive(TreeNode* node);
	void add(int toadd);
	int height();
	void remove(int toremove);
	bool hasPathSum(int sum);
	void printPaths();
	int minValue();
	int maxValue();
	int isBST();
	int isBST2();

private:
	int isBST(TreeNode* node);
	int isBSTRecur(TreeNode* node, int min, int max);
	void pretty_print(const TreeNode* node);
	void pretty_print(std::string prefix, const TreeNode* node, bool isLeft);
	int minValue(TreeNode* node);
	int maxValue(TreeNode* node);
	void printArray(int path[], int len);
	void printPaths(TreeNode* node);
	void printPathsRecur(TreeNode* n, int path[], int pathLen);
	int hasPathSum(TreeNode* root, int sum);
	void add(TreeNode* toAdd, TreeNode* addHere);
	void remove(TreeNode* addHere, int toremove);
	TreeNode* FindMin(TreeNode* node);
	int height(TreeNode* node);
	TreeNode* root;
};