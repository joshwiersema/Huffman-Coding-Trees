#include "HuffTree.h"

HuffTree::HuffTree() {
    root = nullptr;
}

HuffTree::HuffTree(char el, int wt) {
    root = std::make_shared<HuffLeafNode>(el, wt);
}

HuffTree::HuffTree(std::shared_ptr<IHuffNode> l, std::shared_ptr<IHuffNode> r, int wt) {
    root = std::make_shared<HuffInternalNode>(l, r, wt);
}

std::shared_ptr<IHuffNode> HuffTree::getRoot() {
    return root;
}

int HuffTree::weight() {
    return root->weight();
}

bool HuffTree::operator==(HuffTree& other){
    return this->weight() == other.weight();
}

bool HuffTree::operator<(HuffTree& other){
    return this->weight() < other.weight();
}

bool HuffTree::operator>(HuffTree& other){
    return this->weight() > other.weight();
}

bool HuffTree::operator<=(HuffTree& other){
    return this->weight() <= other.weight();
}

bool HuffTree::operator>=(HuffTree& other){
    return this->weight() >= other.weight();
}

/**
 * Helper function to find the Huffman code for a single character
 * Recursively searches the tree for the target character
 * @param node The current node being examined
 * @param target The character to find
 * @param path The current path (string of 0s and 1s)
 * @param result The resulting path when character is found
 * @return true if character is found, false otherwise
 */
bool findChar(std::shared_ptr<IHuffNode> node, char target, std::string path, std::string& result) {
    if(node == nullptr) {
        return false;
    }
    
    // Check if this is a leaf node
    if(node->isLeaf()) {
        std::shared_ptr<HuffLeafNode> leaf = std::static_pointer_cast<HuffLeafNode>(node);
        if(leaf->value() == target) {
            result = path;
            return true;
        }
        return false;
    }
    
    // It's an internal node, search left and right
    std::shared_ptr<HuffInternalNode> internal = std::static_pointer_cast<HuffInternalNode>(node);
    
    // Go left (add '0')
    if(findChar(internal->left(), target, path + "0", result)) {
        return true;
    }
    
    // Go right (add '1')
    if(findChar(internal->right(), target, path + "1", result)) {
        return true;
    }
    
    return false;
}

/**
 * Encodes a string using the Huffman tree
 * Goes through each character and finds its code in the tree
 * @param s The string to encode
 * @return The encoded string as a sequence of 0s and 1s
 */
std::string HuffTree::encode(std::string s) {
    std::string result = "";
    
    // Encode each character one at a time
    for(int i = 0; i < s.length(); i++) {
        std::string charCode = "";
        findChar(root, s[i], "", charCode);
        result += charCode;
    }
    
    return result;
}

/**
 * Decodes a Huffman code string back into the original text
 * Traverses the tree: 0 means go left, 1 means go right
 * When a leaf is reached, that's a character
 * @param code The encoded string (sequence of 0s and 1s)
 * @return The decoded string
 */
std::string HuffTree::decode(std::string code) {
    std::string result = "";
    std::shared_ptr<IHuffNode> current = root;
    
    // Process each bit in the code
    for(int i = 0; i < code.length(); i++) {
        // If we're at a leaf, we found a character
        if(current->isLeaf()) {
            std::shared_ptr<HuffLeafNode> leaf = std::static_pointer_cast<HuffLeafNode>(current);
            result += leaf->value();
            current = root; // Start over for next character
        }
        
        // Move through tree based on bit
        if(!current->isLeaf()) {
            std::shared_ptr<HuffInternalNode> internal = std::static_pointer_cast<HuffInternalNode>(current);
            if(code[i] == '0') {
                current = internal->left();
            } else {
                current = internal->right();
            }
        }
    }
    
    // Get the last character if we ended at a leaf
    if(current != nullptr && current->isLeaf()) {
        std::shared_ptr<HuffLeafNode> leaf = std::static_pointer_cast<HuffLeafNode>(current);
        result += leaf->value();
    }
    
    return result;
}