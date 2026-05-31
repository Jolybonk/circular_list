#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>
#include <stdexcept>

template<typename T>
class CircularDoublyList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
        Node(T&& value) : data(std::move(value)), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* current;
    size_t sz;

    void copy_from(const CircularDoublyList& other);
    void swap(CircularDoublyList& other) noexcept;

public:
    // Life cycle
    CircularDoublyList();
    CircularDoublyList(const CircularDoublyList& other);
    CircularDoublyList(CircularDoublyList&& other) noexcept;
    ~CircularDoublyList();

    // Assignment
    CircularDoublyList& operator=(const CircularDoublyList& other);
    CircularDoublyList& operator=(CircularDoublyList&& other) noexcept;

    // Insert before/after current
    void insert_before(const T& value);
    void insert_before(T&& value);
    void insert_after(const T& value);
    void insert_after(T&& value);

    void remove_current();

    void next();
    void prev();

    T* get_current();
    const T* get_current() const;

    size_t size() const { return sz; }
    bool empty() const { return sz == 0; }

    // Friend declaration for output operator
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const CircularDoublyList<U>& list);
};

#include "circular_list.hpp"

#endif
