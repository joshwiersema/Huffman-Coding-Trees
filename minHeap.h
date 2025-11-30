#pragma once
#include <vector>
#include <iostream>
#include "HuffTree.h"

// our class implementation for a max heap modified to handle a HuffTree instead of an int
// This needs to be changed to a min heap for Huffman coding
class minHeap {
public:
    /**
     * Default constructor for minHeap
     */
    minHeap();

    /**
     * Constructor for minHeap that builds the heap from an existing vector of elements
     * @param elements The vector of elements to build the heap from
     */
    minHeap(std::vector<HuffTree>& elements);

    /**
     * Insert a new value into the min heap
     * @param value The value to insert
     */
    void insert(HuffTree value);

    /**
     * Delete and return the minimum value from the min heap
     * @return The minimum value
     */
    HuffTree deleteMin();

    /**
     * Check if the min heap is empty
     * @return True if the heap is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * Get the size of the min heap
     * @return The number of elements in the heap
     */
    int size();
    

private:
    std::vector<HuffTree> data;

    /**
     * Get the parent index of a given node index
     * This will use a zero-based index
     * @param index The index of the current node
     * @return The index of the parent node
     */
    int parentIndex(int index);

    /**
     * Get the left child index of a given node index
     * This will use a zero-based index
     * @param index The index of the current node
     * @return The index of the left child
     */
    int leftChildIndex(int index);
    
    /**
     * Get the right child index of a given node index
     * This will use a zero-based index
     * @param index The index of the current node
     * @return The index of the right child
     */
    int rightChildIndex(int index);

    /**
     * Percolate a node up to maintain the min heap property
     * @param index The index of the node to percolate up
     */
    void percolateUp(int index);

    /**
     * Percolate a node down to maintain the min heap property
     * @param index The index of the node to percolate down
     */
    void percolateDown(int index);

    /**
     * Build the min heap from the current data vector
     * This is done by percolating down from the last non-leaf node to the root
     */
    void buildheap();
};