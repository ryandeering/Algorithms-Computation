// AC-CA1.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

//Ryan Deering

//Algorithms and Computation - CA1


#include <iostream>
#include <string>
#include <fstream>

class TreeNode {
    friend class BinaryTree;
    TreeNode(int data);
    friend std::ostream& operator<<(std::ostream& out, const TreeNode* node);

private:
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
    friend class TreeNode;

public:
    BinaryTree();
    ~BinaryTree();
    void add(int);
    TreeNode* deSerialise(std::ifstream& InFile);
    int Serialise(std::ofstream& OutFile);
    

private:
    int serialise(std::ofstream& fp, TreeNode* root);
    void add(TreeNode* toAdd, TreeNode* attachHere);
    TreeNode* root;
};

BinaryTree::BinaryTree() {}

BinaryTree::~BinaryTree() {
    delete root;  // will recursively delete all nodes below it as well
}

void BinaryTree::add(int toAdd) {
    TreeNode* temp = new TreeNode(toAdd);

    if (root == nullptr) {
        root = temp;
        return;
    }

    add(temp, root);
}

//Implemented from the notes
void BinaryTree::add(TreeNode* toAdd, TreeNode* attachHere) {
    if (toAdd->data < attachHere->data) {
        if (attachHere->left == nullptr) {
            attachHere->left = toAdd;
            return;
        }
        add(toAdd, attachHere->left);
    }
    else if (toAdd->data >= attachHere->data) {
        if (attachHere->right == nullptr) {
            attachHere->right = toAdd;
            return;
        }
        add(toAdd, attachHere->right);
    }
}

int BinaryTree::serialise(std::ofstream& fp, TreeNode* root) {
    if (fp.is_open()) {
        if (root == nullptr) return 1;

        fp << root->data << std::endl; //Takes in int into the outstream
        serialise(fp, root->left);
        serialise(fp, root->right);
    }
    else {
        return -1;
    }
}

TreeNode* BinaryTree::deSerialise(std::ifstream& InFile) {
    if (InFile.is_open()) {
        std::string val;

        while (getline(InFile, val)) {
            if (!InFile.eof()) { //gets every line until end of file
                // runs until end of file
                add(std::stoi(val));
            }
        }

        return root;
    }
    return nullptr;
}

int BinaryTree::Serialise(std::ofstream& OutFile) {
    int result = serialise(OutFile, root);
    OutFile.close();

    return result;
}

TreeNode::TreeNode(int dataIn) { data = dataIn; }

//Took some remembering from Data Structures and Algorithms to figure this one out.
//I had to look at some labs from last year.
std::ostream& operator<<(std::ostream& out, const TreeNode* node) {
    if (node == nullptr) {
        return out;
    }
    out << node->data << std::endl;
    out << node->left << std::endl;//preorder traversal, data, left then right
    out << node->right << std::endl;

    return out;
}  // It works but buggy.

// Ryan Deering

// Algorithms and Computation - CA1

int main() {
    std::string filepath = "bst.txt";
    std::ofstream outstream(filepath);
    std::ifstream instream(filepath);

    BinaryTree bst1 = BinaryTree();

    bst1.add(7);
    bst1.add(6566);
    bst1.add(122);
    bst1.add(33);
    bst1.add(4);
    bst1.add(66);
    bst1.add(12);
    bst1.add(22);

    std::cout << std::endl;
    std::cout << "Did writing to file succeed? 1 for yes -1 for no.....RESULT: "
        << bst1.Serialise(outstream) << std::endl;
    std::cout << std::endl;
    std::cout << "New BST generated from deserialized file." << std::endl;

    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Printing deserialised BST in preorder traversal.." << std::endl;

    BinaryTree bst2 = BinaryTree(); //creating new object to prove that it is being deserialised
	std::cout << bst2.deSerialise(instream);

    return 0;
}
