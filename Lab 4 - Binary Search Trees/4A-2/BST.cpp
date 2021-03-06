#include "BST.h"
#include <algorithm>
#include <iostream>

// From geeks for geeks, not sure what but I used it in 4A too
void BST::add(char c) {
  TreeNode* node = new TreeNode(c);
  if (root == nullptr) {
    root = new TreeNode(c);
    return;
  }
  add(node, root);
}

void BST::add(TreeNode* toAdd, TreeNode* addHere) {
  if (toAdd->data < addHere->data) {
    if (addHere->left == nullptr) {
      addHere->left = toAdd;
      return;
    }
    add(toAdd, addHere->left);
  } else if (toAdd->data >= addHere->data) {
    if (addHere->right == nullptr) {
      addHere->right = toAdd;
      return;
    }
    add(toAdd, addHere->right);
  }
}

// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

void BST::printinAscOrder() { AscOrder(root); }
void BST::printPreOrder() { PreOrder(root); }
void BST::printPostOrder() { PostOrder(root); }
bool BST::search(char c) { return search(c, root); }
BST::BST() {}

void BST::AscOrder(TreeNode* node) {
  if (node != nullptr) {
    AscOrder(node->left);
    std::cout << node->data << std::endl;
    AscOrder(node->right);
  }
}

void BST::PreOrder(TreeNode* node) {
  if (node == nullptr) {
    return;
  }
  std::cout << node->data << std::endl;
  PreOrder(node->left);
  PreOrder(node->right);
}

void BST::PostOrder(TreeNode* node) {
  if (node == nullptr) {
    return;
  }
  PostOrder(node->left);
  PostOrder(node->right);
  std::cout << node->data << std::endl;
}

// https://www.techiedelight.com/search-given-key-in-bst/
bool BST::search(char c, TreeNode* node) {
  if (node == nullptr) {
    return false;
  }

  else if (node->data == c) {
    return true;
  }

  else if (node->data > c) {
    return search(c, node->left);
  }

  else if (node->data < c) {
    return search(c, node->right);
  }
}
