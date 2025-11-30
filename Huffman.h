#pragma once
#include <string>
#include "HuffTree.h"
#include "minHeap.h"


class Huffman{
private:
    std::string message;
    HuffTree myTree;
    minHeap HufHeap;
    
public:
    Huffman();
    Huffman(std::string msg);
    void huffify();
    HuffTree buildTree();
    std::string encodeMessage(std::string msg);
    std::string decodeMessage(std::string code);
};