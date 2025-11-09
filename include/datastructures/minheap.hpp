#ifndef MINHEAP
#define MINHEAP
#include "vector.hpp"

template <typename Item>
class MinHeap {
private:
  Vector<Item> vector;

  int parentIndex(int index);
  int leftChildIndex(int index);
  int rightChildIndex(int index);
  void heapifyUp(int index);
  void heapifyDown(int index);

public:
  // Constructors and Destructors
  MinHeap();
  ~MinHeap();

  // Attributes
  int getSize() const;
  bool empty() const;

  // Operations
  void insert(Item value);
  void extractMin();
  Item getMin() const;
};

#endif
