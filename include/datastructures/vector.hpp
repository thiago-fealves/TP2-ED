#ifndef VECTOR
#define VECTOR
#include <stdexcept>

template <typename Item>
class Vector {
private:
  Item* array; 
  int size;
  int capacity;
  void doubleArray();
public:
  // Constructors, Destructors and Internals
  Vector();
  Vector(int capacity);
  ~Vector();
  Vector(const Vector& other);
  Vector& operator=(const Vector& other);

  // Attributes
  int getSize() const;
  int getCapacity() const;
  bool empty() const;

  // Operations
  Item& getAt(int index) const;
  void insertAt(int index, Item value);
  void deleteAt(int index);
  void append(Item value);
  void swap(int a, int b);
  void removeLast();
};

/* Constructors and Destructors */
template <typename Item>
Vector<Item>::Vector() : size(0), capacity(1) {
  array = new Item[1]; 
}

template <typename Item>
Vector<Item>::Vector(int capacity) : size(0), capacity(capacity) {
  array = new Item[capacity]; 
}

template <typename Item>
Vector<Item>::~Vector() {
  delete[] array;
}

/* Double function */
template <typename Item>
void Vector<Item>::doubleArray() {
  Item* new_array = new Item[capacity * 2];
  for (int i = 0; i < size; i++) {
    new_array[i] = array[i];
  }
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
Item& Vector<Item>::getAt(int index) const {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }

  return array[index]; 
}

template <typename Item>
void Vector<Item>::append(Item value) {
  if (size >= capacity) {
    doubleArray();
  }
  array[size] = value;
  size++;
}

template <typename Item>
void Vector<Item>::insertAt(int index, Item value) {
  if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
  }
  
  if (size >= capacity) {
    doubleArray();
  }

  for (int i = size; i > index; i--) {
    array[i] = array[i - 1];
  }

  array[index] = value;
  size++;
}

template <typename Item>
void Vector<Item>::removeLast() {
  if (this->empty()) {
    throw std::out_of_range("Array is empty");
  } 
  size--;
}

template <typename Item>
void Vector<Item>::swap(int i, int j) {
  if (i < 0 || i >= size || j < 0 || j >= size) {
    throw std::out_of_range("Index out of range");
  }
  Item temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

template <typename Item>
void Vector<Item>::deleteAt(int index) {
  if (this->empty() || index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }

  for (int i = index; i < size - 1; i++) {
    array[i] = array[i + 1];
  }
  size--;
}

template <typename Item>
Vector<Item>::Vector(const Vector& other) {
    this->capacity = other.capacity;
    this->size = other.size;
    this->array = new Item[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->array[i] = other.array[i];
    }
}

template <typename Item>
Vector<Item>& Vector<Item>::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] this->array;
    this->capacity = other.capacity;
    this->size = other.size;
    this->array = new Item[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->array[i] = other.array[i];
    }
    return *this;
}

#endif
