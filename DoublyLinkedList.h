#include  <iostream>
using namespace std;

template <typename T>
class DNode{
    public:
        T data ;
        DNode<T> * prev;
        DNode<T> * next;
};

template <typename T>
class DoublyLinkedList
{
private:
    DNode<T> * head;
    DNode<T> * tail;
    int length;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    T front();
    T back();
    void traverseForword();
    void insertStart(T data);
    void insertEnd(T data);
    void insertByPosition(T data,int position);
    void deleteStart();
    void deleteEnd();
    void deleteByPosition(int position);
    void deleteByValue(T data);
    int Dsize();
    bool isEmpty();

};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length= 0;
}


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


template <typename T>
void DoublyLinkedList<T>::insertByPosition(T data,int position){

    if(position <0 || position>length){
        cout << "Enter a valid position"<<endl;
        return;
    }


    if(position==0){
        insertStart(data);
        return;
    }
    if(position==length){
        insertEnd(data);
        return;
    }   

    DNode<T>* newDNode = new DNode<T>();
    newDNode->data = data;
    newDNode->next = nullptr;
    newDNode->prev = nullptr;

    DNode<T>* temp = head;

    for(int i=0;i<position;i++){
        temp = temp->next;
    }

    newDNode->prev = temp->prev;
    newDNode->next = temp;
    temp->prev->next = newDNode;
    temp->prev = newDNode;

    length++;
}

template <typename T>
void DoublyLinkedList<T>::traverseForword(){
    if(!isEmpty()){
        DNode<T>* temp = head;
        while(temp!= nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }else{
        cout <<"list is empty" << endl;
    }

}

template <typename T>
void DoublyLinkedList<T>::deleteStart(){
    if(!isEmpty()){
        DNode<T>* temp = head;

        if (head == tail)   // only one node
        {
            head = tail = nullptr;
        }else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }else{
        cout << "list is empty" << endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteEnd(){
    if(!isEmpty()){
        DNode<T>* temp = tail;

        if (head == tail)   // only one node
        {
            head = tail = nullptr;
        }else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }else{
        cout << "list is empty" << endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteByPosition(int position){

    if(position<0 || position>=length && !isEmpty()){
        cout << "Enter a valid position";
        return;
    }

    if(position==0){
        deleteStart();
        return;
    }

    if(position==length-1){
        deleteEnd();
        return;
    }



    DNode<T> * temp ;

    if(position < length/2){

        temp = head ;
        for(int i=0;i<position;i++){
            temp  = temp->next;
        }

    }else { 

        temp  = tail ;
        for(int i=length-1;i>position;i--){
            temp  = temp->prev;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp ->prev;

    delete temp;
    length--;
}


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
        cout << "item " << data << " not found";
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

template <typename T>
T DoublyLinkedList<T>::front(){
    return head->data;
}


template <typename T>
T DoublyLinkedList<T>::back(){
    return tail->data;
}


template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return head == nullptr;
}

template <typename T>
int DoublyLinkedList<T>::Dsize(){
    return length;
}


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DNode<T> * temp ;

    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    length = 0;
}





