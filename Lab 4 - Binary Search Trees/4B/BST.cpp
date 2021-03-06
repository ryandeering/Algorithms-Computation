#pragma once
#include "BST.h"
#include <iostream>
#include <string>

BST::~BST() {
    delete root;  // will recursively delete all nodes below it as well
}

void BST::add(int toadd) {
    TreeNode* temp = new TreeNode(toadd);

    if (root == nullptr) {
        root = temp;
        return;  // return necessary?
    }

    add(temp, root);
}

void BST::add(TreeNode* toAdd, TreeNode* addHere) {
    if (toAdd->data < addHere->data) {
        if (addHere->left == nullptr) {
            addHere->left = toAdd;
            return;
        }
        add(toAdd, addHere->left);
    }
    else if (toAdd->data >= addHere->data) {
        if (addHere->right == nullptr) {
            addHere->right = toAdd;
            return;
        }
        add(toAdd, addHere->right);
    }
}

int BST::height() { return height(root); }

// https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
int BST::height(TreeNode* root) {
    if (root == nullptr)
        return -1;
    else {
        /* compute the depth of each subtree */

        int lDepth = height(root->left);
        int rDepth = height(root->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void BST::remove(int toremove) {
    if (root == nullptr) return;

    remove(root, toremove);
}

// I can't find the link for where I referenced this
// I keep searching my Google history and I'm getting a 504 when I try to do a
// search on Feb 19th.
// In either case, I used the link and the Powerpoint from the class

void BST::remove(TreeNode* addHere, int toremove) {
    if (addHere == nullptr) {
        // Case: nullptr

        std::cout << "val not found in tree" << std::endl;

    }
    else if (toremove == addHere->data) {
        // Found value

        TreeNode* trash = nullptr;
        if (addHere->left == nullptr && addHere->right == nullptr) {
            // Case: node is a leaf

            trash = addHere;
            addHere = nullptr;

        }
        else if (addHere->left != nullptr && addHere->right == nullptr) {
            // Case: node has a left subtree (but not right)
            // Point node's parent at node's left subtree

            trash = addHere;
            addHere = addHere->left;

        }
        else if (addHere->left == nullptr && addHere->right != nullptr) {
            // Case: node has a right subtree (but not left)
            trash = addHere;
            addHere = addHere->right;
            root = addHere;

        }
        else {
            // Case: node has left and right subtrees

            TreeNode* minNode = FindMin(
                addHere->right);  // returns a reference to the pointer in the tree
            addHere->data = minNode->data;
            this->remove(minNode, minNode->data);
        }

        // Free memory

    }
    else if (toremove < addHere->data) {
        // Case: remove val from this node's left subtree
        this->remove(addHere->left, toremove);
    }
    else {
        // Case: remove val from this node's right subtree
        this->remove(addHere->right, toremove);
    }
}

TreeNode* BST::FindMin(TreeNode* node) {
    if (node == nullptr) {
        throw "Min value not found";
    }
    else if (node->left == nullptr) {
        return node;
    }
    else {
        return this->FindMin(node->left);
    }
}

// special thanks to James Lynam for this, I had no bloody clue.
int BST::hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return (sum == 0);
    }
    else {
        int summary = sum - root->data;
        return (hasPathSum(root->left, summary) | hasPathSum(root->right, summary));
    }
}

bool BST::hasPathSum(int sum) { return hasPathSum(root, sum); }

// https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/

void BST::printPathsRecur(TreeNode* n, int path[], int pathLen) {
    if (n == nullptr) {
        return;
    }
    /* Append this node to the path array */
    path[pathLen] = n->data;
    pathLen++;

    /* It's a leaf, so print the path that led to here */
    if ((n->left == nullptr) && (n->right == nullptr)) {
        printArray(path, pathLen);
    }
    else {
        /* Otherwise try both subtrees */
        printPathsRecur(n->left, path, pathLen);
        printPathsRecur(n->right, path, pathLen);
    }
}

void BST::printPaths(TreeNode* node) {
    int path[1000];
    printPathsRecur(node, path, 0);
}
void BST::printPaths() { printPaths(root); }

void BST::printArray(int path[], int len) {
    for (int i = 0; i < len; i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
}

// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void BST::pretty_print() { pretty_print(root); }
void BST::pretty_print(const TreeNode* node) { pretty_print("", node, false); }
void BST::pretty_print(std::string prefix, const TreeNode* node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "|__");

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        pretty_print(prefix + (isLeft ? "|   " : "    "), node->left, true);
        pretty_print(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

int BST::minValue(TreeNode* node) {
    if (node->left == nullptr) {
        return node->data;
    }
    minValue(node->left);
}

int BST::minValue() {
    if (root == nullptr) {
        return 0;
    }
    return minValue(root);
}

int BST::maxValue(TreeNode* node) {
    if (node->right == nullptr) {
        return node->data;
    }
    maxValue(node->right);
}

int BST::maxValue() {
    if (root == nullptr) {
        return 0;
    }
    return maxValue(root);
}

// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
int BST::isBST(TreeNode* node)  // Correct, but not efficient
{
    if (node == nullptr) {
        return true;
    }
    if (node->left != nullptr && maxValue(node->left) > node->data) {
        return false;
    }

    if (node->right != nullptr && minValue(node->right) <= node->data) {
        return false;
    }

    if (!isBST(node->left) || !isBST(node->right)) {
        return false;
    }

    return true;
}

// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
int BST::isBSTRecur(TreeNode* node, int min, int max) {
    if (node == nullptr) {
        return true;
    }

    // If we violate our min or max, we return false
    if (node->data < min || node->data > max) return (false);

    return isBSTRecur(node->left, min,
        node->data - 1) &&  // Allow only distinct values
        isBSTRecur(node->right, node->data + 1,
            max);  // Allow only distinct values
}

int BST::isBST2() { return (isBSTRecur(root, INT_MIN, INT_MAX)); }

int BST::isBST() { return isBST(root); }

BST::BST() {}