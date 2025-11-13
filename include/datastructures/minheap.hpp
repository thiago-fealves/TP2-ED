#ifndef MINHEAP
#define MINHEAP
#include "vector.hpp"

template <typename Item>
class MinHeap {
private:
  Vector<Item> vector;

  // Indexing
  int getParentIndex(int index);
  int getLeftChildIndex(int index);
  int getRightChildIndex(int index);

  // Heapify
  void heapifyUp(int index);
  void heapifyDown(int index);

public:
  // Constructors
  MinHeap();
  MinHeap(int capacity);
  
  // Attributes
  int getSize() const;
  bool empty() const;

  // Operations
  void insert(Item value);
  void deleteMin();
  Item getMin() const;
  Item extractMin();
};

/* Constructors */
template <typename Item>
MinHeap<Item>::MinHeap(): vector() {}

template <typename Item>
MinHeap<Item>::MinHeap(int capacity): vector(capacity) {}

/* Indexing */
template <typename Item>
int MinHeap<Item>::getParentIndex(int index) { return (index - 1) / 2; }

template <typename Item>
int MinHeap<Item>::getLeftChildIndex(int index) { return 2 * index + 1; }

template <typename Item>
int MinHeap<Item>::getRightChildIndex(int index) { return 2 * index + 2; }

/* Attributes */
template <typename Item>
int MinHeap<Item>::getSize() const { return vector.getSize(); }

template <typename Item>
bool MinHeap<Item>::empty() const { return vector.empty(); }

/* Heapify */
template <typename Item>
void MinHeap<Item>::heapifyUp(int index) {
  while (index > 0) {
    int parent = getParentIndex(index);
    if (vector.getAt(index) < vector.getAt(parent)) {
      vector.swap(index, parent);
      index = parent;
    } else break;
  }
}

template <typename Item>
void MinHeap<Item>::heapifyDown(int index) {
  int size = getSize();
  while (true) {
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);
    int smallest = index;

    if (left < size && vector.getAt(left) < vector.getAt(smallest))
      smallest = left;
    if (right < size && vector.getAt(right) < vector.getAt(smallest))
      smallest = right;

    if (smallest != index) {
      vector.swap(index, smallest);
      index = smallest;
    } else break;
  }
}

/* Operations */
template <typename Item>
void MinHeap<Item>::insert(Item value) {
  vector.append(value);
  heapifyUp(vector.getSize() - 1);
}

template <typename Item>
Item MinHeap<Item>::getMin() const {
  if (empty())
    throw std::out_of_range("MinHeap is empty");
  return vector.getAt(0);
}

template <typename Item>
void MinHeap<Item>::deleteMin() {
  if (empty())
    throw std::out_of_range("MinHeap is empty");

  int last = vector.getSize() - 1;
  vector.swap(0, last);
  vector.deleteAt(last);

  if (!empty())
    heapifyDown(0);
}

template <typename Item>
Item MinHeap<Item>::extractMin() {
  Item min = getMin();
  deleteMin();
  return min;
}

#endif
