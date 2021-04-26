#include "HuffmanTree.h"

#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;

HuffmanTree::HuffmanTree() = default;

HuffmanTree::HuffmanTree(HuffmanTree * leftTree, HuffmanTree * rightTree, int totalWeight)
{
	this->weight = totalWeight;
	root = new HuffmanNode();
	root->left = leftTree;
	root->right = rightTree;
}

HuffmanTree::HuffmanTree(int data, int weight) :
    weight{ weight },
    root{ new HuffmanNode(data) } {  }


/***************************************************************************************

*    Usage: Used, but with a map instead
*    Title: Frequency of each character in a String using unordered_map in C++
*    Author: hrishikeshkonderu
*    Date: 26 Oct, 2020
*    Code version: 1.0
*    Availability: https://www.geeksforgeeks.org/frequency-of-each-character-in-a-string-using-unordered_map-in-c/
*
***************************************************************************************/

map<char, int> HuffmanTree::printCharacterFrequency(string str)
{
    map<char, int> M;


    for (int i = 0; str[i]; i++)
    {

        if (M.find(str[i]) == M.end())
        {
            M.insert(make_pair(str[i], 1));
        }

        else
        {
            M[str[i]]++;
        }
    }

    for (auto& it : M) {
        cout << it.first << ' ' << it.second << '\n';
    }

    return M;
}


/***************************************************************************************

*    Usage: Used but modified upon. Was crucial to understand the boiling down of the priority queue in tree construction
*    Title: Huffman Coding using Priority Queue
*    Author: namang133
*    Date:  11 Sep, 2020
*    Code version: 1.0
*    Availability: https://www.geeksforgeeks.org/huffman-coding-using-priority-queue/
*
***************************************************************************************/
HuffmanTree* HuffmanTree::buildHuffmanTree(std::map<char, int> char_frequency) {
    priority_queue<HuffmanTree*, vector<HuffmanTree*>, Comparison> queue;

    auto it = char_frequency.begin(); //more modern C++ than using non-auto type, hope this is ok
    while (it != char_frequency.end()) {
        queue.push(new HuffmanTree(it->first, it->second));
        ++it;
    }

    if (!queue.empty()) {
        while (queue.size() > 1) { //boiling down priority queue
            HuffmanNode* newNode = new HuffmanNode();
            newNode->left = queue.top();
            queue.pop(); //takes elements of queue
            newNode->right = queue.top();
            queue.pop(); 

            queue.push(new HuffmanTree(newNode->left, newNode->right, newNode->left->weight+newNode->right->weight));
        }
    }
    return queue.top(); //returns the top of the queue, boiled down
}

void HuffmanTree::encode(HuffmanNode* root, string path, std::map<char, string>& encoded) //Encodes path of character
{
    if (root->character) {
        encoded.insert(make_pair(root->character, path)); // left, 0
        return;                                                    // right, 1
    }
    if (root->left) {
        encode(root->left->root, path + "0", encoded);
    }
    if (root->right) {
        encode(root->right->root, path + "1", encoded);
    }
}

void HuffmanTree::encode(map<char, string>& encoded) //recursive solution for encoding
{
    string path;
    return encode(root, path, encoded);
}


string HuffmanTree::decode(HuffmanTree* root, string encodedString) //self-explanatory
{
    string decodedString;
    HuffmanTree* temp = root;   //+1 because it kept cutting off at the last character? works 
    for (int i = 0; i < encodedString.length()+1; i++)
    {

        // reached a character
        if (temp->root->character)
        {
            decodedString += temp->root->character;
            temp = root;
            i--;
        }
    	else if(encodedString[i] == '0')
        {
            temp = temp->root->left;
        }
    	else if(encodedString[i] == '1')
        {
            temp = temp->root->right;
        }
       
    }
    std::cout<<decodedString<<endl;
    return decodedString;
}


/***************************************************************************************

*    Usage: Used
*    Title: Convert a string of binary into an ASCII string (C++)
*    Author: Dale Wilson
*    Date: Apr 28 '14
*    Code version: 2.0
*    Availability: https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c/  
*
***************************************************************************************/
std::string HuffmanTree::compress8BitChunk(string encodedString)
{
    int not8bit = encodedString.size() % 8; //anything not divisible by eight? add zeroes

    for (int i = 0; i < not8bit; i++) {
        encodedString.push_back('0');
    }

    string compressedString;
    std::stringstream stream(encodedString);
    string output;
    while (stream.good())
    {
        bitset<8> bit_set; // This is a more modern C++ solution to this problem, but it is better than nothing
        stream >> bit_set;
        uint8_t chunk = uint8_t(bit_set.to_ulong());
        compressedString.push_back(chunk);
    }

    return compressedString;
}

std::string HuffmanTree::decompress8BitChunk(string compressedString)
{
    std::string decompressedString = "";

    int not8bit = compressedString.size() % 8;

    for (int i = 0; i < compressedString.length(); i++)
    {
        bitset<8> temp(compressedString[i]); //get binary code of each uint8_t
        decompressedString += temp.to_string();
    }

    for (int i = 0; i < not8bit; i++)
    {
        decompressedString.pop_back();
    }
    return decompressedString;
}

bool Comparison::operator() (const HuffmanTree* lhs, const HuffmanTree* rhs) const
{
    return lhs->weight > rhs->weight;
}
