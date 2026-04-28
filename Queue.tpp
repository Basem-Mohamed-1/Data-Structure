#include "Queue.h"

/**
 * @file Queue.tpp
 * @brief Implementation of the Queue class template methods.
 */

/**
 * @brief Returns the current number of elements in the queue.
 * 
 * @tparam T The type of elements stored in the queue.
 * @return int The size of the queue.
 * 
 * @complexity O(1)
 */
template <typename T>
int Queue<T>::size(){
    return list.size();
}

/**
 * @brief Adds an element to the back of the queue.
 * 
 * @tparam T The type of elements stored in the queue.
 * @param data The element to be added to the queue (passed by const reference).
 * 
 * @complexity O(1)
 */
template <typename T>
void Queue<T>::push(const T & data){
    list.insertEnd(data);
}

/**
 * @brief Removes the front element from the queue.
 * 
 * @tparam T The type of elements stored in the queue.
 * 
 * @pre The queue must not be empty.
 * @complexity O(1)
 */
template <typename T>
void Queue<T>::pop(){
    list.deleteStart();
}

/**
 * @brief Returns the front element without removing it.
 * 
 * @tparam T The type of elements stored in the queue.
 * @return T A copy of the front element.
 * 
 * @pre The queue must not be empty.
 * @complexity O(1)
 */
template <typename T>
T Queue<T>::front() const{
    return list.front();
}

/**
 * @brief Returns the back element without removing it.
 * 
 * @tparam T The type of elements stored in the queue.
 * @return T A copy of the back element.
 * 
 * @pre The queue must not be empty.
 * @complexity O(1)
 */
template <typename T>
T Queue<T>::back() const{
    return list.back();
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @tparam T The type of elements stored in the queue.
 * @return true if the queue contains no elements, false otherwise.
 * 
 * @complexity O(1)
 */
template <typename T>
bool Queue<T>::isEmpty(){
    return list.isEmpty();
}