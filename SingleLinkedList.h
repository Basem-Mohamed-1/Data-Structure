#pragma once

namespace DataStructures {

/**
 * @file SingleLinkedList.h
 * @brief Header file for a singly linked list implementation.
 */

/**
 * @brief A node in the singly linked list.
 * 
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class SNode {
public:
    T data;           /**< The data stored in the node. */
    SNode<T>* next;   /**< Pointer to the next node in the list. */

    /**
     * @brief Constructs a new SNode.
     * 
     * @param data The data to store in the node. Defaults to 0.
     */
    SNode(T data = 0) : data(data), next(nullptr) {}
};

/**
 * @brief A singly linked list container.
 * 
 * Provides basic operations for manipulating a singly linked list,
 * including insertion, deletion, and access operations.
 * 
 * @tparam T The type of elements stored in the list.
 */
template <typename T>
class SingleLinkedList {
private:
    SNode<T>* head;   /**< Pointer to the first node in the list. */
    int length;       /**< Current number of nodes in the list. */

public:
    /**
     * @brief Constructs an empty singly linked list.
     */
    SingleLinkedList<T>();

    /**
     * @brief Destroys the list and releases all allocated memory.
     */
    ~SingleLinkedList<T>();

    /**
     * @brief Prints all elements in the list.
     */
    void print();

    /**
     * @brief Inserts a new element at the front of the list.
     * 
     * @param data The element to insert.
     * 
     * @complexity O(1)
     */
    void insertFront(T data);

    /**
     * @brief Inserts a new element at the end of the list.
     * 
     * @param data The element to insert.
     * 
     * @complexity O(n) where n is the number of elements.
     */
    void insertEnd(T data);

    /**
     * @brief Inserts a new element at the specified position.
     * 
     * @param data The element to insert.
     * @param position The index at which to insert (0-based). Defaults to 0.
     * 
     * @pre 0 <= position <= size()
     * @complexity O(n) where n is the number of elements.
     */
    void insert(T data, int position = 0);

    /**
     * @brief Removes the first element from the list.
     * 
     * @pre The list must not be empty.
     * @complexity O(1)
     */
    void deleteFront();

    /**
     * @brief Removes the last element from the list.
     * 
     * @pre The list must not be empty.
     * @complexity O(n) where n is the number of elements.
     */
    void deleteEnd();

    /**
     * @brief Removes the first occurrence of a specific value from the list.
     * 
     * @param data The value to remove.
     * 
     * @complexity O(n) where n is the number of elements.
     */
    void deleteByValue(T data);

    /**
     * @brief Removes the element at the specified position.
     * 
     * @param position The index of the element to remove (0-based).
     * 
     * @pre 0 <= position < size()
     * @complexity O(n) where n is the number of elements.
     */
    void deleteByPosition(int position);

    /**
     * @brief Checks if the list is empty.
     * 
     * @return true If the list contains no nodes.
     * @return false If the list contains at least one node.
     * 
     * @complexity O(1)
     */
    bool isEmpty();

    /**
     * @brief Returns the first element without removing it.
     * 
     * @return T A copy of the element at the head of the list.
     * 
     * @pre The list must not be empty.
     * @complexity O(1)
     */
    T front() const;

    /**
     * @brief Returns the current number of elements in the list.
     * 
     * @return int The size of the list.
     * 
     * @complexity O(1)
     */
    int size();
};

#include "SingleLinkedList.tpp"

} // namespace DataStructures