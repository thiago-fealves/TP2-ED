#ifndef NODE_HPP
#define NODE_HPP

/* Definition */
template <typename Data>
class Node {
  public:
    Node* previous;
    Data data;
    Node* next;
    
    Node();
    Node(Data data);
    ~Node();
};

/* Implementation */
template <typename Data>
Node<Data>::Node() : previous(nullptr), data(), next(nullptr) {}

template <typename Data>
Node<Data>::Node(Data data) : previous(nullptr), data(data), next(nullptr) {}

template <typename Data>
Node<Data>::~Node() {
    previous = nullptr;
    next = nullptr;
}

#endif
