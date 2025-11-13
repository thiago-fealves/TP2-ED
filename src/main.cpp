#include <iostream>
#include "datastructures/minheap.hpp"

int main() {
  MinHeap<int> heap;

  // Inserindo valores
  heap.insert(10);
  heap.insert(4);
  heap.insert(15);
  heap.insert(20);
  heap.insert(0);
  heap.insert(8);

  std::cout << "Heap size: " << heap.getSize() << std::endl;
  std::cout << "Min element: " << heap.getMin() << std::endl;

  // Extraindo elementos em ordem crescente
  std::cout << "\nExtraindo elementos:" << std::endl;
  while (!heap.empty()) {
    std::cout << heap.extractMin() << " ";
  }
  std::cout << std::endl;

  return 0;
}
