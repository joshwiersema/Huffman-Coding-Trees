#include "HuffBaseNode.h"


HuffLeafNode::HuffLeafNode(char el, int w){
    element = el;
    elementWeight = w;
}

char HuffLeafNode::value(){
    return element;
}

bool HuffLeafNode::isLeaf() {
    return true;
}

int HuffLeafNode::weight() {
    return elementWeight;
}

HuffInternalNode::HuffInternalNode(std::shared_ptr<IHuffNode> left, std::shared_ptr<IHuffNode> right, int w){
    leftChild = left;
    rightChild = right;
    elementWeight = w;
}

std::shared_ptr<IHuffNode> HuffInternalNode::left() {
    return leftChild;
}

std::shared_ptr<IHuffNode> HuffInternalNode::right() {
    return rightChild;
}

bool HuffInternalNode::isLeaf() {
    return false;
}

int HuffInternalNode::weight() {
    return elementWeight;
}