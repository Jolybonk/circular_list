#include "circular_list.h"
#include <iostream>
#include <vector>
#include <string>

void demo_single_list() {
    std::cout << "=== Single List Demonstration ===\n";
    CircularDoublyList<int> list;

    list.insert_after(10);
    std::cout << "After insert_after(10): " << list << std::endl;

    list.insert_before(5);
    std::cout << "After insert_before(5): " << list << std::endl;

    list.insert_after(15);
    std::cout << "After insert_after(15): " << list << std::endl;

    list.next();
    std::cout << "After next(), current element: " << *list.get_current() << std::endl;

    list.insert_before(12);
    std::cout << "After insert_before(12): " << list << std::endl;

    list.remove_current();
    std::cout << "After remove_current(): " << list << std::endl;

    // Copy
    CircularDoublyList<int> copy = list;
    std::cout << "Copy: " << copy << std::endl;
    copy.insert_after(100);
    std::cout << "Copy after modification: " << copy << std::endl;
    std::cout << "Original unchanged: " << list << std::endl;

    // Move
    CircularDoublyList<int> moved = std::move(copy);
    std::cout << "Moved list: " << moved << std::endl;
    std::cout << "Source after move: " << copy << " (empty)\n";

    // Exception handling
    try {
        CircularDoublyList<int> empty;
        empty.remove_current();
    } catch (const std::logic_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void demo_list_of_lists() {
    std::cout << "\n=== List of Lists ===\n";
    const int N = 4;
    std::vector<CircularDoublyList<std::string>> lists(N);

    lists[0].insert_after("A0"); lists[0].insert_after("B0");
    lists[1].insert_after("A1");
    // lists[2] stays empty
    lists[3].insert_after("A3"); lists[3].insert_after("B3"); lists[3].insert_after("C3");

    for (size_t i = 0; i < N; ++i)
        std::cout << "List " << i << ": " << lists[i] << std::endl;

    std::cout << "\nRemoving current element from each list:\n";
    for (size_t i = 0; i < N; ++i) {
        try {
            lists[i].remove_current();
            std::cout << "List " << i << " after removal: " << lists[i] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "List " << i << " error: " << e.what() << std::endl;
        }
    }

    std::cout << "\nInserting into each list:\n";
    for (size_t i = 0; i < N; ++i) {
        try {
            lists[i].insert_after("NEW_" + std::to_string(i));
            std::cout << "List " << i << " after insert: " << lists[i] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "List " << i << " insert error: " << e.what() << std::endl;
        }
    }

    // Copy list 3 to list 2
    lists[2] = lists[3];
    std::cout << "\nAfter copying list 3 to list 2:\n";
    std::cout << "List 2: " << lists[2] << "\nList 3: " << lists[3] << std::endl;

    // Move list 0
    auto moved = std::move(lists[0]);
    std::cout << "\nMoved list 0: " << moved << "\nOriginal list 0: " << lists[0] << std::endl;

    std::cout << "\nAll exceptions handled, program continues.\n";
}

int main() {
    demo_single_list();
    demo_list_of_lists();
    return 0;
}
