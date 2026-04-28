#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

/**
 * @file SingleLinkedList.tpp
 * @brief Implementation of the SingleLinkedList class template methods.
 */

/**
 * @brief Returns the current number of elements in the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @return int The size of the list.
 * 
 * @complexity O(1)
 */
template <typename T>
int SingleLinkedList<T>::size(){
    return length;
}

/**
 * @brief Constructs an empty singly linked list.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @complexity O(1)
 */
template <typename T>
SingleLinkedList<T>::SingleLinkedList(){
    head = nullptr;
    length = 0;
}

/**
 * @brief Inserts a new element at the front of the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The element to insert.
 * 
 * @complexity O(1)
 */
template <typename T>
void SingleLinkedList<T>::insertFront(T data){
    SNode<T>* newSNode = new SNode<T>();
    newSNode->data = data;
    newSNode->next = head;
    head = newSNode;
    length++;
}

/**
 * @brief Inserts a new element at the specified position.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The element to insert.
 * @param position The index at which to insert (0-based). Defaults to 0.
 * 
 * @pre 0 <= position <= size()
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void SingleLinkedList<T>::insert(T data, int position){
    try{
        if(position < 0 || position > length){
            throw invalid_argument("invalid position");
        }

        if(position == 0){
            insertFront(data);
            return;
        }
        
        if(position == length){
            insertEnd(data);
            return;
        }

        SNode<T>* newSNode = new SNode<T>();
        newSNode->data = data;

        SNode<T>* temp = head;
        for(int i = 0; i < position - 1; i++){
            temp = temp->next;
        }
        newSNode->next = temp->next;
        temp->next = newSNode;
        length++;
    }
    catch(exception &e){
        cout << e.what();
    }
}

/**
 * @brief Inserts a new element at the end of the list.
 * 
 * @tparam T The type of elements stored in the list.
 * @param data The element to insert.
 * 
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void SingleLinkedList<T>::insertEnd(T data){
    SNode<T>* newSNode = new SNode<T>();
    newSNode->data = data;
    newSNode->next = nullptr;

    // Case of empty linked list
    if(head == nullptr){
        head = newSNode;
        length++;
        return;
    }

    // Case of non-empty list
    SNode<T>* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newSNode;
    length++;
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
void SingleLinkedList<T>::deleteFront(){
    try{
        if(length == 0) throw invalid_argument("list is empty\n");

        SNode<T>* temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    catch(exception &e){
        cout << e.what();
    }
}

/**
 * @brief Removes the last element from the list.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @pre The list must not be empty.
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void SingleLinkedList<T>::deleteEnd(){
    try{
        if(head == nullptr){
            cout << "list is empty" << endl;
            return;
        }

        SNode<T>* temp = head;

        // Case: Single element in the list
        if(length == 1){
            delete head;
            head = nullptr;
            length--;
            return;
        }

        SNode<T>* prev = nullptr;
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        delete temp;
        length--;
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
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
void SingleLinkedList<T>::deleteByValue(T data){
    try{
        if(head == nullptr){
            throw invalid_argument("list is empty");
        }

        // If the value to delete is at the head
        if(head->data == data){
            SNode<T>* temp = head;
            head = head->next;
            delete temp;
            length--;
            return;
        }

        SNode<T>* prev = head;
        SNode<T>* temp = head->next;

        while(temp != nullptr && temp->data != data){
            prev = temp;
            temp = temp->next;
        }

        if(temp == nullptr){
            cout << "Value not Found" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        length--;
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
}

/**
 * @brief Removes the element at the specified position.
 * 
 * @tparam T The type of elements stored in the list.
 * @param position The index of the element to remove (0-based).
 * 
 * @pre 0 <= position < size()
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void SingleLinkedList<T>::deleteByPosition(int position){
    try{
        if(position < 0 || position >= length){
            throw invalid_argument("invalid position");
        }

        if(head == nullptr){
            cout << "Empty List" << endl;
            return;
        }

        if(position == 0){
            deleteFront();
            return;
        }

        if(position == length - 1 && length - 1 != 0){
            deleteEnd();
            return;
        }

        SNode<T>* temp = head;
        SNode<T>* prev = temp;

        for(int i = 0; i < position; i++){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
        length--;
    }
    catch(exception &e){
        cout << e.what();
    }
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
bool SingleLinkedList<T>::isEmpty(){
    return head == nullptr;
}

/**
 * @brief Prints all elements in the list.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
void SingleLinkedList<T>::print(){
    if(head == nullptr){
        cout << "empty list " << endl;
        return;
    }

    SNode<T>* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/**
 * @brief Returns the first element without removing it.
 * 
 * @tparam T The type of elements stored in the list.
 * @return T A copy of the element at the head of the list.
 * 
 * @note Returns -1 if the list is empty (only valid for integer types).
 * 
 * @pre The list must not be empty for meaningful results.
 * @complexity O(1)
 */
template <typename T>
T SingleLinkedList<T>::front() const {
    if(head != nullptr) return head->data;
    else return -1;  // Sentinel value - only appropriate for numeric types
}

/**
 * @brief Destroys the list and releases all allocated memory.
 * 
 * Iterates through the list and deletes each node.
 * 
 * @tparam T The type of elements stored in the list.
 * 
 * @complexity O(n) where n is the number of elements.
 */
template <typename T>
SingleLinkedList<T>::~SingleLinkedList(){
    SNode<T>* temp = head;
    while(temp != nullptr){
        SNode<T>* next = temp->next;
        delete temp;
        temp = next;
    }
}