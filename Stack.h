#pragma once
#include "SingleLinkedList.h"

namespace DataStructures{

/**
 * @brief A generic Stack implementation using a singly linked list as the underlying container.
 * 
 * This class provides standard LIFO (Last-In-First-Out) stack operations.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class Stack 
{
private:
    DataStructures::SingleLinkedList<T> list; /**< Underlying singly linked list container */
    int length; /**< Current number of elements in the stack */
    
public:
    /**
     * @brief Constructs an empty stack.
     */
    Stack<T>();
    
    /**
     * @brief Destroys the stack and releases all allocated memory.
     */
    ~Stack<T>();
    
    /**
     * @brief Pushes an element onto the top of the stack.
     * 
     * @param data The element to be added to the stack.
     */
    void push(T data);
    
    /**
     * @brief Removes the top element from the stack.
     */
    void pop();
    
    /**
     * @brief Returns the current number of elements in the stack.
     * 
     * @return int The size of the stack.
     */
    int size();
    
    /**
     * @brief Checks if the stack is empty.
     * 
     * @return true if the stack contains no elements, false otherwise.
     */
    bool isEmpty();
    
    /**
     * @brief Prints all elements in the stack from top to bottom.
     */
    void print();
    
    /**
     * @brief Returns a reference to the top element without removing it.
     * 
     * @return T A copy of the top element.
     */
    T top() const;
};

#include "Stack.tpp"

} // namespace DataStructures