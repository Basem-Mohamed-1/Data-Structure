#pragma once
#include "Stack.h"

/**
 * @file Stack.tpp
 * @brief Implementation of the Stack class template methods.
 */

/**
 * @brief Pushes an element onto the top of the stack.
 * 
 * Inserts the element at the front of the underlying linked list.
 * 
 * @tparam T The type of elements stored in the stack.
 * @param data The element to push onto the stack.
 * 
 * @complexity O(1)
 */
template <typename T>
void Stack<T>::push(T data){
    list.insertFront(data);
    length++;
}

/**
 * @brief Removes the top element from the stack.
 * 
 * Deletes the front element of the underlying linked list.
 * 
 * @tparam T The type of elements stored in the stack.
 * 
 * @pre The stack must not be empty.
 * @complexity O(1)
 */
template <typename T>
void Stack<T>::pop(){
    list.deleteFront();
    length--;
}

/**
 * @brief Returns the current number of elements in the stack.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return int The number of elements in the stack.
 * 
 * @complexity O(1)
 */
template <typename T>
int Stack<T>::size(){
    return length;
}

/**
 * @brief Checks if the stack is empty.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return true If the stack contains no elements.
 * @return false If the stack contains at least one element.
 * 
 * @complexity O(1)
 */
template <typename T>
bool Stack<T>::isEmpty(){
    return list.isEmpty();
}

/**
 * @brief Prints all elements in the stack from top to bottom.
 * 
 * Outputs the stack contents using the underlying list's print method.
 * 
 * @tparam T The type of elements stored in the stack.
 * 
 * @complexity O(n) where n is the number of elements in the stack.
 */
template <typename T>
void Stack<T>::print(){
    list.print();
}

/**
 * @brief Returns the top element without removing it.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return T A copy of the element at the top of the stack.
 * 
 * @pre The stack must not be empty.
 * @complexity O(1)
 */
template <typename T>
T Stack<T>::top() const{
    return list.front();
}

/**
 * @brief Constructs an empty stack.
 * 
 * Initializes the stack with zero elements.
 * 
 * @tparam T The type of elements stored in the stack.
 * 
 * @complexity O(1)
 */
template <typename T>
Stack<T>::Stack()
{
    length = 0;
}

/**
 * @brief Destroys the stack.
 * 
 * The underlying linked list's destructor will automatically clean up all nodes.
 * 
 * @tparam T The type of elements stored in the stack.
 * 
 * @complexity O(n) where n is the number of elements in the stack.
 */
template <typename T>
Stack<T>::~Stack()
{
    // Destructor body is empty because the SingleLinkedList destructor
    // will automatically handle memory deallocation.
}