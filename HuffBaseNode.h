#pragma once
#include <memory>

/**
 * Abstract base class for Huffman Tree nodes
 */
class IHuffNode{
public:
    /**
     * Determines if the node is a leaf node
     * @return true if leaf node, false otherwise
     */
    virtual bool isLeaf() = 0;
    /**
     * Returns the weight of the node
     * @return weight of the node
     */
    virtual int weight() = 0;
};

/**
 * Class representing a leaf node in the Huffman Tree
 */
class HuffLeafNode : public IHuffNode {
public:
    /**
     * Constructor for HuffLeafNode
     * @param el character element stored in the leaf
     * @param w weight of the leaf node
     */
    HuffLeafNode(char el, int w);
    /**
     * Gets the character value stored in the leaf node
     * @return character value
     */
    char value();
    /**
     * Indicates that this node is a leaf
     * @return true
     */
    bool isLeaf() override;
    /**
     * Returns the weight of the leaf node
     * @return weight of the node
     */
    int weight() override;
private:
    char element;
    int elementWeight;
};

/**
 * Class representing an internal node in the Huffman Tree
 */
class HuffInternalNode : public IHuffNode {
public:
    /**
     * Constructor for HuffInternalNode
     * @param left left child node
     * @param right right child node
     * @param w weight of the internal node
     */
    HuffInternalNode(std::shared_ptr<IHuffNode> left, std::shared_ptr<IHuffNode> right, int w);
    /**
     * Returns the left child node
     * @return left child node
     */
    std::shared_ptr<IHuffNode> left();
    /**
     * Returns the right child node
     * @return right child node
     */
    std::shared_ptr<IHuffNode> right();
    /**
     * Indicates that this node is not a leaf
     * @return false
     */
    bool isLeaf() override;
    /**
     * Returns the weight of the internal node
     * @return weight of the node
     */
    int weight() override;
private:
    std::shared_ptr<IHuffNode> leftChild;
    std::shared_ptr<IHuffNode> rightChild;
    int elementWeight;
};