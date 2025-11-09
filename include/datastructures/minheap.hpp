#ifndef MINHEAP
#define MINHEAP
#include "vector.hpp"

template <typename T>
class MinHeap {
private:
  Vector<T> vector;

  void heapify();
  void getLowerChild();
  void getHigherChild();
  void getParent();
public:
  void insert();
  void remove();
};

#endif
