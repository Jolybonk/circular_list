#ifndef CIRCULAR_LIST_HPP
#define CIRCULAR_LIST_HPP

#include "circular_list.h"
#include <utility>

// Helper methods
template<typename T>
void CircularDoublyList<T>::copy_from(const CircularDoublyList& other) {
    if (other.empty()) {
        head = current = nullptr;
        sz = 0;
        return;
    }

    // Copy all nodes starting from other.head
    Node* other_node = other.head;
    Node* new_node = new Node(other_node->data);
    head = new_node;
    Node* tail = new_node;

    other_node = other_node->next;
    while (other_node != other.head) {
        Node* copy = new Node(other_node->data);
        tail->next = copy;
        copy->prev = tail;
        tail = copy;
        other_node = other_node->next;
    }
    tail->next = head;
    head->prev = tail;
    sz = other.sz;

    // Locate current position in the new list
    if (other.current == nullptr) {
        current = nullptr;
    } else {
        // Find index of other.current relative to other.head
        size_t idx = 0;
        Node* tmp = other.head;
        while (tmp != other.current) {
            tmp = tmp->next;
            ++idx;
        }
        current = head;
        for (size_t i = 0; i < idx; ++i) {
            current = current->next;
        }
    }
}

template<typename T>
void CircularDoublyList<T>::swap(CircularDoublyList& other) noexcept {
    std::swap(head, other.head);
    std::swap(current, other.current);
    std::swap(sz, other.sz);
}

// Life cycle
template<typename T>
CircularDoublyList<T>::CircularDoublyList() : head(nullptr), current(nullptr), sz(0) {}

template<typename T>
CircularDoublyList<T>::CircularDoublyList(const CircularDoublyList& other) {
    copy_from(other);
}

template<typename T>
CircularDoublyList<T>::CircularDoublyList(CircularDoublyList&& other) noexcept
    : head(other.head), current(other.current), sz(other.sz) {
    other.head = other.current = nullptr;
    other.sz = 0;
}

template<typename T>
CircularDoublyList<T>::~CircularDoublyList() {
    if (empty()) return;
    Node* node = head;
    do {
        Node* next = node->next;
        delete node;
        node = next;
    } while (node != head);
}

// Assignment
template<typename T>
CircularDoublyList<T>& CircularDoublyList<T>::operator=(const CircularDoublyList& other) {
    if (this != &other) {
        CircularDoublyList tmp(other);
        swap(tmp);
    }
    return *this;
}

template<typename T>
CircularDoublyList<T>& CircularDoublyList<T>::operator=(CircularDoublyList&& other) noexcept {
    if (this != &other) {
        swap(other);
        other.head = other.current = nullptr;
        other.sz = 0;
    }
    return *this;
}

// Insert before current
template<typename T>
void CircularDoublyList<T>::insert_before(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        head = current = new_node;
        new_node->next = new_node->prev = new_node;
        sz = 1;
        return;
    }
    Node* prev_node = current->prev;
    new_node->prev = prev_node;
    new_node->next = current;
    prev_node->next = new_node;
    current->prev = new_node;
    if (current == head) {
        head = new_node;
    }
    ++sz;
}

template<typename T>
void CircularDoublyList<T>::insert_before(T&& value) {
    Node* new_node = new Node(std::move(value));
    if (empty()) {
        head = current = new_node;
        new_node->next = new_node->prev = new_node;
        sz = 1;
        return;
    }
    Node* prev_node = current->prev;
    new_node->prev = prev_node;
    new_node->next = current;
    prev_node->next = new_node;
    current->prev = new_node;
    if (current == head) {
        head = new_node;
    }
    ++sz;
}

// Insert after current
template<typename T>
void CircularDoublyList<T>::insert_after(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        head = current = new_node;
        new_node->next = new_node->prev = new_node;
        sz = 1;
        return;
    }
    Node* next_node = current->next;
    new_node->prev = current;
    new_node->next = next_node;
    current->next = new_node;
    next_node->prev = new_node;
    ++sz;
}

template<typename T>
void CircularDoublyList<T>::insert_after(T&& value) {
    Node* new_node = new Node(std::move(value));
    if (empty()) {
        head = current = new_node;
        new_node->next = new_node->prev = new_node;
        sz = 1;
        return;
    }
    Node* next_node = current->next;
    new_node->prev = current;
    new_node->next = next_node;
    current->next = new_node;
    next_node->prev = new_node;
    ++sz;
}

// Remove current
template<typename T>
void CircularDoublyList<T>::remove_current() {
    if (empty()) throw std::logic_error("remove_current: list is empty");
    if (sz == 1) {
        delete current;
        head = current = nullptr;
        sz = 0;
        return;
    }
    Node* to_remove = current;
    Node* new_current = current->next;
    Node* prev_node = current->prev;
    Node* next_node = current->next;
    prev_node->next = next_node;
    next_node->prev = prev_node;
    if (to_remove == head) {
        head = next_node;
    }
    delete to_remove;
    current = new_current;
    --sz;
}

// Navigation
template<typename T>
void CircularDoublyList<T>::next() {
    if (empty()) throw std::logic_error("next: list is empty");
    current = current->next;
}

template<typename T>
void CircularDoublyList<T>::prev() {
    if (empty()) throw std::logic_error("prev: list is empty");
    current = current->prev;
}

// Access
template<typename T>
T* CircularDoublyList<T>::get_current() {
    if (empty()) throw std::logic_error("get_current: list is empty");
    return &(current->data);
}

template<typename T>
const T* CircularDoublyList<T>::get_current() const {
    if (empty()) throw std::logic_error("get_current: list is empty");
    return &(current->data);
}

// Output operator
template<typename U>
std::ostream& operator<<(std::ostream& os, const CircularDoublyList<U>& list) {
    if (list.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    typename CircularDoublyList<U>::Node* node = list.head;
    do {
        os << node->data;
        node = node->next;
        if (node != list.head) os << ", ";
    } while (node != list.head);
    os << "]";
    return os;
}

#endif
