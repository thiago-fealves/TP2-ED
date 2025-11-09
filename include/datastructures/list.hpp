#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>
#include "node.hpp"

template <typename Item>
class List {
public:
    Node<Item>* head;
    Node<Item>* tail;
    int length;

    // Constructors
    List() : head(nullptr), tail(nullptr), length(0) {}
    List(const Item &data) {
        Node<Item>* item = new Node<Item>(data);
        head = tail = item;
        length = 1;
    }
    template <size_t N>
    List(const Item (&arr)[N]) : head(nullptr), tail(nullptr), length(0) {
        for (size_t i = 0; i < N; i++) append(arr[i]);
    }

    // Main functions
    void addAt(int index, const Item &data);
    void append(const Item &data); 
    Item& getAt(int index) const;
    int getIndex(const Item &data);
    void deleteAt(int index);

    // Merge Sort
    void sort() {
        if (length <= 1) return;
        head = mergeSort(head);
        
        // After sorting, we need to find the new tail
        tail = head;
        if (tail) {
            while(tail->next) {
                tail = tail->next;
            }
        }
    }

private:
    Node<Item>* mergeSort(Node<Item>* h);
    Node<Item>* getMiddle(Node<Item>* h);
    Node<Item>* sortedMerge(Node<Item>* a, Node<Item>* b);
};

// Implementation
template <typename Item>
void List<Item>::addAt(int index, const Item &data) {
    if (index < 0 || index > length) return;

    Node<Item>* prev = nullptr;
    Node<Item>* current = head;
    for (int i = 0; i < index; ++i) {
        prev = current;
        current = current->next;
    }

    Node<Item>* item = new Node<Item>(data);
    item->previous = prev;
    item->next = current;

    if (prev) prev->next = item; else head = item;
    if (current) current->previous = item; else tail = item;

    length++;
}

template <typename Item>
Item& List<Item>::getAt(int index) const {
    if (index < 0 || index >= length) throw std::out_of_range("Index out of range");
    Node<Item>* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    return current->data;
}

template <typename Item>
void List<Item>::append(const Item &data) {
    Node<Item>* newNode = new Node<Item>(data);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    length++;
}

template <typename Item>
int List<Item>::getIndex(const Item &data) {
    Node<Item>* current = head;
    int i = 0;
    while (current) {
        if (current->data == data) return i;
        current = current->next;
        i++;
    }
    return -1;
}

template <typename Item>
void List<Item>::deleteAt(int index) {
    if (index < 0 || index >= length) return;

    Node<Item>* current = head;
    for (int i = 0; i < index; ++i) current = current->next;

    if (current->previous) current->previous->next = current->next;
    else head = current->next;

    if (current->next) current->next->previous = current->previous;
    else tail = current->previous;

    delete current;
    length--;
}

// --- MergeSort implementation ---
template <typename Item>
Node<Item>* List<Item>::sortedMerge(Node<Item>* a, Node<Item>* b) {
    if (!a) return b;
    if (!b) return a;

    Node<Item>* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    // Update the 'previous' pointer for the doubly-linked list
    if (result->next) {
        result->next->previous = result;
    }
    return result;
}

template <typename Item>
Node<Item>* List<Item>::getMiddle(Node<Item>* h) {
    if (!h) return h;
    Node<Item>* slow = h;
    Node<Item>* fast = h->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


template <typename Item>
Node<Item>* List<Item>::mergeSort(Node<Item>* h) {
    if (!h || !h->next) {
        return h;
    }

    Node<Item>* middle = getMiddle(h);
    Node<Item>* nextOfMiddle = middle->next;
    
    // Separating halfs
    middle->next = nullptr;
    if (nextOfMiddle) {
        nextOfMiddle->previous = nullptr;
    }

    // Orders recursively
    Node<Item>* left = mergeSort(h);
    Node<Item>* right = mergeSort(nextOfMiddle);

    // Merge
    return sortedMerge(left, right);
}

#endif
