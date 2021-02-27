#pragma once

class TreeNode {
  friend class BST;
  // public:
  TreeNode();
  TreeNode(int data);
  ~TreeNode();

 private:
  int data;
  TreeNode* left;
  TreeNode* right;
};