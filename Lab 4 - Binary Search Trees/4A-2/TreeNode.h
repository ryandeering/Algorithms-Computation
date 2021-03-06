#pragma once

class TreeNode {
  friend class BST;

 public:
  TreeNode();
  TreeNode(char data);

 private:
  char data;
  TreeNode* left;
  TreeNode* right;
};