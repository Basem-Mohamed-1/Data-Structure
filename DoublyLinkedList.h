#pragma once

namespace DataStructures
{

/**
 * @file DoublyLinkedList.h
 * @brief Header file for a doubly linked list implementation.
 */

/**
 * @brief A node in the doubly linked list.
 * 
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class DNode {
public:
    T data;           /**< The data stored in the node. */
    DNode<T>* prev;   /**< Pointer to the previous node in the list. */
    DNode<T>* next;   /**< Pointer to the next node in the list. */
};

/**
 * @brief A doubly linked list container.
 * 
 * Provides operations for manipulating a doubly linked list with both
 * head and tail pointers for efficient access to both ends.
 * 
 * @tparam T The type of elements stored in the list.
 */
template <typename T>
class DoublyLinkedList
{
private:
    DNode<T>* head;   /**< Pointer to the first node in the list. */
    DNode<T>* tail;   /**< Pointer to the last node in the list. */
    int length;       /**< Current number of nodes in the list. */

public:
    /**
     * @brief Constructs an empty doubly linked list.
     */
    DoublyLinkedList();

    /**
     * @brief Destroys the list and releases all allocated memory.
     */
    ~DoublyLinkedList();

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
     * @brief Returns the last element without removing it.
     * 
     * @return T A copy of the element at the tail of the list.
     * 
     * @pre The list must not be empty.
     * @complexity O(1)
     */
    T back() const;

    /**
     * @brief Traverses and prints all elements from head to tail.
     * 
     * @complexity O(n) where n is the number of elements.
     */
    void traverseForword();

    /**
     * @brief Inserts a new element at the beginning of the list.
     * 
     * @param data The element to insert.
     * 
     * @complexity O(1)
     */
    void insertStart(T data);

    /**
     * @brief Inserts a new element at the end of the list.
     * 
     * @param data The element to insert.
     * 
     * @complexity O(1)
     */
    void insertEnd(T data);

    /**
     * @brief Inserts a new element at the specified position.
     * 
     * @param data The element to insert.
     * @param position The index at which to insert (0-based).
     * 
     * @pre 0 <= position <= size()
     * @complexity O(n) where n is the number of elements.
     */
    void insertByPosition(T data, int position);

    /**
     * @brief Removes the first element from the list.
     * 
     * @pre The list must not be empty.
     * @complexity O(1)
     */
    void deleteStart();

    /**
     * @brief Removes the last element from the list.
     * 
     * @pre The list must not be empty.
     * @complexity O(1)
     */
    void deleteEnd();

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
     * @brief Removes the first occurrence of a specific value from the list.
     * 
     * @param data The value to remove.
     * 
     * @complexity O(n) where n is the number of elements.
     */
    void deleteByValue(T data);

    /**
     * @brief Returns the current number of elements in the list.
     * 
     * @return int The size of the list.
     * 
     * @complexity O(1)
     */
    int size();

    /**
     * @brief Checks if the list is empty.
     * 
     * @return true If the list contains no nodes.
     * @return false If the list contains at least one node.
     * 
     * @complexity O(1)
     */
    bool isEmpty();
};

#include "DoublyLinkedList.tpp"

} // namespace DataStructures