#pragma once
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

 private:
  void add(TreeNode* toAdd, TreeNode* addHere);
  void remove(TreeNode* addHere, int toremove);
  TreeNode* FindMin(TreeNode* node);
  int height(TreeNode* node);
  TreeNode* root;
};