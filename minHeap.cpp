#include "minHeap.h"

minHeap::minHeap(){
    data = std::vector<HuffTree>();
}

minHeap::minHeap(std::vector<HuffTree>& elements) {
    data = elements;
    buildheap();
}


int minHeap::parentIndex(int index) {
    return (index - 1) / 2;
}


int minHeap::leftChildIndex(int index) {
    return 2 * index + 1;
}

int minHeap::rightChildIndex(int index) {
    return 2 * index + 2;
}

void minHeap::percolateUp(int index) {
    int parentIdx = parentIndex(index);
    while(parentIdx >= 0 && data[index] < data[parentIdx]) {
        // Swap the values
        HuffTree temp = data[index];
        data[index] = data[parentIdx];
        data[parentIdx] = temp;
        // Move up the tree to next levels
        index = parentIdx;
        parentIdx = parentIndex(index);
    }
}

void minHeap::insert(HuffTree value) {
    data.push_back(value); // Add the new value at the end
    percolateUp(data.size() - 1); // Percolate it up to maintain heap property

}

void minHeap::percolateDown(int index) {
    while (leftChildIndex(index) < (int)data.size()) {
        int leftIndex = leftChildIndex(index);
        int rightIndex = rightChildIndex(index);
        int smallerChildIndex = leftIndex;

        // Pick the smaller child
        if (rightIndex < (int)data.size() && data[rightIndex] < data[leftIndex]) {
            smallerChildIndex = rightIndex;
        }

        // If parent is bigger than the smaller child, swap
        if (data[index] > data[smallerChildIndex]) {
            std::swap(data[index], data[smallerChildIndex]);
            index = smallerChildIndex;
        } else {
            break; // heap property restored
        }
    }
}


HuffTree minHeap::deleteMin() {
    HuffTree minValue = data[0];
    data[0] = data.back();
    data.pop_back();
    percolateDown(0);
    return minValue;
}

void minHeap::buildheap() {
    for(int i = parentIndex(data.size() - 1); i >= 0; i--) {
        percolateDown(i);
    }

}

bool minHeap::isEmpty() const {
    return data.empty();
}

int minHeap::size() {
    return data.size();
}