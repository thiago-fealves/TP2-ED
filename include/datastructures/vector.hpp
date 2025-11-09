#ifndef VECTOR
#define VECTOR
#include <stdexcept>

template <typename Item>
class Vector {
private:
  Item** array;
  int size;
  int capacity;
  void doubleArray();

public:
  // Constructors and Destructors
  Vector();
  ~Vector();

  // Attributes
  int getSize() const;
  int getCapacity() const;
  bool empty() const;

  // Operations
  Item* getAt(int index);
  void insertAt(int index, Item value);
  void deleteAt(int index);
  void append(Item value);
};

/* Constructors and Destructors */
template <typename Item>
Vector<Item>::Vector() : array(new Item*[1]), size(0), capacity(1) {
  array[0] = nullptr;
}

template <typename Item>
Vector<Item>::~Vector() {
  for (int i = 0; i < capacity; i++) {
    delete array[i];
  }
  delete[] array;
}

/* Double function */
template <typename Item>
void Vector<Item>::doubleArray() {
  Item** new_array = new Item*[capacity * 2];
  for (int i = 0; i < capacity * 2; i++) new_array[i] = nullptr;
  for (int i = 0; i < capacity; i++) new_array[i] = array[i];
  delete[] array;
  array = new_array;
  capacity *= 2;
}

/* Attributes */
template <typename Item>
int Vector<Item>::getSize() const { return size; }

template <typename Item>
int Vector<Item>::getCapacity() const { return capacity; }

template <typename Item>
bool Vector<Item>::empty() const { return size == 0; }

/* Operations */
template <typename Item>
Item* Vector<Item>::getAt(int index) {
  if (index < 0 || index >= capacity) {
    throw std::out_of_range("Index out of range");
  }
  return array[index];
}

template <typename Item>
void Vector<Item>::insertAt(int index, Item value) {
  while (index >= capacity) {
    doubleArray();
  }
  if (array[index] == nullptr) size++;
  array[index] = new Item(value);
}

template <typename Item>
void Vector<Item>::deleteAt(int index) {
  if (index < 0 || index >= capacity) {
    throw std::out_of_range("Index out of range");
  }
  if (array[index] != nullptr) {
    delete array[index];
    array[index] = nullptr;
    size--;
  }
}

template <typename Item>
void Vector<Item>::append(Item value) {
  insertAt(size, value);
}

#endif
