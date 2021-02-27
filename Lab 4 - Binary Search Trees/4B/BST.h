#pragma once
#include "TreeNode.h"
class BST {
  friend class TreeNode;

 public:
  BST();

  void add(char c);
  bool search(char c);
  void printinAscOrder();
  void printPreOrder();
  void printPostOrder();

 private:
  void add(TreeNode* toAdd, TreeNode* addHere);
  bool search(char c, TreeNode* node);
  void AscOrder(TreeNode* node);
  void PreOrder(TreeNode* node);
  void PostOrder(TreeNode* node);

  TreeNode* root;
};
