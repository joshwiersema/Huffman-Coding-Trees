#include "Huffman.h"

/**
 * Default constructor for Huffman
 * Initializes with default message "Hello World!"
 */
Huffman::Huffman(){
    message = "Hello World!";
}

/**
 * Constructor for Huffman with custom message
 * @param msg The message to encode/decode using Huffman coding
 */
Huffman::Huffman(std::string msg){
    message = msg;
}

/**
 * Builds the Huffman tree from the message by counting character frequencies,
 * creating individual HuffTrees for each character, and combining them using
 * the min heap algorithm
 */
void Huffman::huffify(){
    // Array to count frequency of each character (256 possible ASCII values)
    int frequencies[256] = {0};
    
    // Count frequency of each character in message using simple for loop
    for(int i = 0; i < message.length(); i++) {
        frequencies[(int)message[i]]++;
    }
    
    // Create a HuffTree for each character that appears and add to heap
    for(int i = 0; i < 256; i++) {
        if(frequencies[i] > 0) {
            HuffTree tree((char)i, frequencies[i]);
            HufHeap.insert(tree);
        }
    }
    
    // Build the final Huffman tree
    myTree = buildTree();
}

/**
 * Builds the final Huffman tree by repeatedly combining the two smallest trees
 * @return The final combined Huffman tree
 */
HuffTree Huffman::buildTree(){
    HuffTree temp1, temp2, temp3;
    while(HufHeap.size() > 1){ // While there are two or more items in the heap
        temp1 = HufHeap.deleteMin();
        temp2 = HufHeap.deleteMin();
        temp3 = HuffTree(temp1.getRoot(), temp2.getRoot(), temp1.weight() + temp2.weight());
        HufHeap.insert(temp3); // Insert the new tree back into the heap
    }
    return temp3; // Return the final tree
}

/**
 * Encodes a message using the Huffman tree
 * @param msg The message to encode
 * @return The encoded message as a string of 0s and 1s
 */
std::string Huffman::encodeMessage(std::string msg){
    return myTree.encode(msg);
}

/**
 * Decodes a Huffman code back into the original message
 * @param code The encoded message (string of 0s and 1s)
 * @return The decoded message
 */
std::string Huffman::decodeMessage(std::string code){
    return myTree.decode(code);
}