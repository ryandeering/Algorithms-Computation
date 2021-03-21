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

int BST::Serialise(std::ofstream& OutFile) {
    int result = Serialise(OutFile, root);
    OutFile.close();
    return result;
}

int BST::Deserialise(std::ifstream& InFile) {
    int result = Deserialise(InFile, root);
    InFile.close();
    return result;
}

int BST::Serialise(std::ofstream& OutFile, TreeNode* root) {
    if (OutFile.is_open()) {
        if (root == nullptr) return 1;

        OutFile << root->data << std::endl;
        Serialise(OutFile, root->left);
        Serialise(OutFile, root->right);
    }
    else {
        return -1;
    }
}

int BST::Deserialise(std::ifstream& InFile, TreeNode* root) {
    if (InFile.is_open()) {
        std::string val;

        while (getline(InFile, val)) {
            if (!InFile.eof()) { //runs until end of file
                add(std::stoi(val));
            }
        }

        root = this->root;
    }
    if (root != nullptr) return 1;
    return -1;
}

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

BST::BST() {}