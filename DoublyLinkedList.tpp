#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

/**
 * @file DoublyLinkedList.tpp
 * @brief Implementation of the DoublyLinkedList class template methods.
 */

/**
 * @brief Constructs an empty doubly linked list.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @complexity O(1)
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/**
 * @brief Inserts a new element at the end of the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The element to insert.
 * 
 * @complexity O(1)
 */
template <typename T>
void DoublyLinkedList<T>::insertEnd(T data)
{
    DNode<T>* newDNode = new DNode<T>();
    newDNode->data = data;
    newDNode->next = nullptr;
    newDNode->prev = nullptr;

    if (head == nullptr)
    {
        head = tail = newDNode;
        length++;
        return;
    }

    tail->next = newDNode;
    newDNode->prev = tail;
    tail = newDNode;

    length++;
}

/**
 * @brief Inserts a new element at the beginning of the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The element to insert.
 * 
 * @complexity O(1)
 */
template <typename T>
void DoublyLinkedList<T>::insertStart(T data)
{
    DNode<T>* newDNode = new DNode<T>();
    newDNode->data = data;
    newDNode->next = nullptr;
    newDNode->prev = nullptr;

    if (head == nullptr)
    {
        head = tail = newDNode;
        length++;
        return;
    }

    head->prev = newDNode;
    newDNode->next = head;
    head = newDNode;

    length++;
}

/**
 * @brief Inserts a new element at the specified position.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The element to insert.
 * @param position The index at which to insert (0-based).
 * 
 * @pre 0 <= position <= size()
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void DoublyLinkedList<T>::insertByPosition(T data, int position)
{
    if (position < 0 || position > length)
    {
        cout << "Enter a valid position" << endl;
        return;
    }

    if (position == 0)
    {
        insertStart(data);
        return;
    }
    
    if (position == length)
    {
        insertEnd(data);
        return;
    }

    DNode<T>* newDNode = new DNode<T>();
    newDNode->data = data;
    newDNode->next = nullptr;
    newDNode->prev = nullptr;

    DNode<T>* temp = head;

    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }

    newDNode->prev = temp->prev;
    newDNode->next = temp;
    temp->prev->next = newDNode;
    temp->prev = newDNode;

    length++;
}

/**
 * @brief Traverses and prints all elements from head to tail.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void DoublyLinkedList<T>::traverseForword()
{
    if (!isEmpty())
    {
        DNode<T>* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else
    {
        cout << "list is empty" << endl;
    }
}

/**
 * @brief Removes the first element from the list.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @pre The list must not be empty.
 * @complexity O(1)
 */
template <typename T>
void DoublyLinkedList<T>::deleteStart()
{
    if (!isEmpty())
    {
        DNode<T>* temp = head;

        if (head == tail)   // Only one node in the list
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }
    else
    {
        cout << "list is empty" << endl;
    }
}

/**
 * @brief Removes the last element from the list.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @pre The list must not be empty.
 * @complexity O(1)
 */
template <typename T>
void DoublyLinkedList<T>::deleteEnd()
{
    if (!isEmpty())
    {
        DNode<T>* temp = tail;

        if (head == tail)   // Only one node in the list
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }
    else
    {
        cout << "list is empty" << endl;
    }
}

/**
 * @brief Removes the element at the specified position.
 * 
 * Optimizes traversal by choosing to start from either head or tail
 * based on the position relative to the middle of the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @param position The index of the element to remove (0-based).
 * 
 * @pre 0 <= position < size()
 * @complexity O(n/2) ~ O(n) where n is the number of elements.
 */
template <typename T>
void DoublyLinkedList<T>::deleteByPosition(int position)
{
    if (position < 0 || position >= length && !isEmpty())
    {
        cout << "Enter a valid position";
        return;
    }

    if (position == 0)
    {
        deleteStart();
        return;
    }

    if (position == length - 1)
    {
        deleteEnd();
        return;
    }

    DNode<T>* temp;

    // Optimize by traversing from the closer end
    if (position < length / 2)
    {
        temp = head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
    }
    else
    {
        temp = tail;
        for (int i = length - 1; i > position; i--)
        {
            temp = temp->prev;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    length--;
}

/**
 * @brief Removes the first occurrence of a specific value from the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The value to remove.
 * 
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void DoublyLinkedList<T>::deleteByValue(T data)
{
    if (isEmpty())
    {
        cout << "list is empty";
        return;
    }

    DNode<T>* temp = head;

    while (temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "item " << data << " not found" << endl;
        return;
    }

    if (temp == head)
    {
        deleteStart();
        return;
    }

    if (temp == tail)
    {
        deleteEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    length--;
}

/**
 * @brief Returns the first element without removing it.
 * 
 * @tparam T The type of elements stored in the list.
 * @return T A copy of the element at the head of the list.
 * 
 * @pre The list must not be empty.
 * @complexity O(1)
 */
template <typename T>
T DoublyLinkedList<T>::front() const
{
    return head->data;
}

/**
 * @brief Returns the last element without removing it.
 * 
 * @tparam T The type of elements stored in the list.
 * @return T A copy of the element at the tail of the list.
 * 
 * @pre The list must not be empty.
 * @complexity O(1)
 */
template <typename T>
T DoublyLinkedList<T>::back() const
{
    return tail->data;
}

/**
 * @brief Checks if the list is empty.
 * 
 * @tparam T The type of elements stored in the list.
 * @return true If the list contains no nodes.
 * @return false If the list contains at least one node.
 * 
 * @complexity O(1)
 */
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return head == nullptr;
}

/**
 * @brief Returns the current number of elements in the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @return int The size of the list.
 * 
 * @complexity O(1)
 */
template <typename T>
int DoublyLinkedList<T>::size()
{
    return length;
}

/**
 * @brief Destroys the list and releases all allocated memory.
 * 
 * Iterates through the list from head to tail and deletes each node.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DNode<T>* temp;

    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    length = 0;
}