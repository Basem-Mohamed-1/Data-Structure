#pragma once 
#include "DoublyLinkedList.h"
using namespace DataStructures;

namespace DataStructures {

/**
 * @file Queue.h
 * @brief Header file for a Queue implementation using a doubly linked list.
 */

/**
 * @brief A generic Queue (FIFO) implementation using a doubly linked list as the underlying container.
 * 
 * This class provides standard FIFO (First-In-First-Out) queue operations.
 * Elements are added at the back and removed from the front.
 * 
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>
class Queue
{
private:
    DoublyLinkedList<T> list; /**< Underlying doubly linked list container */

public:
    /**
     * @brief Constructs an empty queue.
     */
    Queue<T>();
    
    /**
     * @brief Destroys the queue and releases all allocated memory.
     */
    ~Queue<T>();
    
    /**
     * @brief Returns the current number of elements in the queue.
     * 
     * @return int The size of the queue.
     * 
     * @complexity O(1)
     */
    int size();
    
    /**
     * @brief Adds an element to the back of the queue.
     * 
     * @param data The element to be added to the queue.
     * 
     * @complexity O(1)
     */
    void push(const T& data);
    
    /**
     * @brief Checks if the queue is empty.
     * 
     * @return true if the queue contains no elements, false otherwise.
     * 
     * @complexity O(1)
     */
    bool isEmpty();
    
    /**
     * @brief Removes the front element from the queue.
     * 
     * @pre The queue must not be empty.
     * @complexity O(1)
     */
    void pop();
    
    /**
     * @brief Returns the front element without removing it.
     * 
     * @return T A copy of the front element.
     * 
     * @pre The queue must not be empty.
     * @complexity O(1)
     */
    T front() const;
    
    /**
     * @brief Returns the back element without removing it.
     * 
     * @return T A copy of the back element.
     * 
     * @pre The queue must not be empty.
     * @complexity O(1)
     */
    T back() const;
};

/**
 * @brief Constructs an empty queue.
 * 
 * @tparam T The type of elements stored in the queue.
 * 
 * @complexity O(1)
 */
template <typename T>
Queue<T>::Queue()
{
    // The DoublyLinkedList constructor is automatically called
    // to initialize the list member.
}

/**
 * @brief Destroys the queue.
 * 
 * The underlying doubly linked list's destructor will automatically
 * clean up all nodes.
 * 
 * @tparam T The type of elements stored in the queue.
 * 
 * @complexity O(n) where n is the number of elements in the queue.
 */
template <typename T>
Queue<T>::~Queue()
{
    // The DoublyLinkedList destructor is automatically called
    // to handle memory deallocation.
}

#include "Queue.tpp"

} // namespace DataStructures