#pragma once
#include <fstream>

#include "TreeNode.h"
class BST {
	friend class TreeNode;

public:
	BST();
	~BST();
	void DestroyRecursive(TreeNode* node);
	void add(int toadd);
	int height();
	void remove(int toremove);
	int Serialise(std::ofstream& OutFile);
	int Deserialise(std::ifstream& InFile);
	void pretty_print();

private:
	int Serialise(std::ofstream& OutFile, TreeNode* root);
	int Deserialise(std::ifstream& InFile, TreeNode* root);
	void pretty_print(const TreeNode* node);
	void pretty_print(std::string prefix, const TreeNode* node, bool isLeft);
	void add(TreeNode* toAdd, TreeNode* addHere);
	void remove(TreeNode* addHere, int toremove);
	TreeNode* FindMin(TreeNode* node);
	int height(TreeNode* node);
	TreeNode* root;
};