#pragma once
#include "HuffBaseNode.h"
#include <string>
#include <memory>

class HuffTree{
public:
    /**
     * Default constructor for HuffTree
     */
    HuffTree();

    /**
     * Constructor for HuffTree
     * @param el character element for leaf node
     * @param wt weight of the node
     */
    HuffTree(char el, int wt);

    /**
     * Constructor for HuffTree
     * @param l left child node
     * @param r right child node
     * @param wt weight of the node
     */
    HuffTree(std::shared_ptr<IHuffNode> l, std::shared_ptr<IHuffNode> r, int wt);

    /**
     * Gets the root node of the Huffman Tree
     * @return root node
     */
    std::shared_ptr<IHuffNode> getRoot();

    /**
     * Returns the weight of the Huffman Tree
     * @return weight of the tree
     */
    int weight();

    /**
     * Several comparison operators for HuffTree based on weight
     * This syntax is probably new to you
     * It allows us to compare two HuffTree objects directly using <, >, ==, etc.
     */
    bool operator==(HuffTree& other);
    bool operator<(HuffTree& other);
    bool operator>(HuffTree& other);
    bool operator<=(HuffTree& other);
    bool operator>=(HuffTree& other);

    //TODO: You implement these and comment them
    std::string encode(std::string s);
    std::string decode(std::string code);
private:
    std::shared_ptr<IHuffNode> root;
};