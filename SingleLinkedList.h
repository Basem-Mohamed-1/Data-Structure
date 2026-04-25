#include  <iostream>
using namespace std;


template <typename T>
class SNode{
    public:
        T data;
        SNode<T> * next;
};

template <typename T>
class SingleLinkedList
{
private:
    SNode<T> *head;
    int length;
    
public:
    
    SingleLinkedList<T>();
    ~SingleLinkedList<T>();
    void print();
    void insertFront(T data);
    void insertEnd(T data);
    void insert(T data,int position=0);
    void deleteFront();
    void deleteEnd();
    void deleteByValue(T data);
    void deleteByPosition(int position);
    int size();


};



template <typename T>
int SingleLinkedList<T>::size(){
    return length;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(){
    head = nullptr;
    length=0;
}

template <typename T>
void SingleLinkedList<T>::insertFront(T data){
    
    SNode<T>* newSNode = new SNode<T>();
    newSNode->data = data;
    newSNode->next = head;
    head = newSNode;
    length++;
}   


template <typename T>
void SingleLinkedList<T>::insert(T data ,int position){
    try{
            if(position <0 ||position>length){
                throw invalid_argument("invalid position");
            } 



            if (position == 0) {
                insertFront(data);
                return;
            }
            if(position==length){
                insertEnd(data);
                return;
            }

            SNode<T> * newSNode = new SNode<T>();
            newSNode->data = data;

            
            SNode<T> * temp= head;
            for(int i=0;i<position-1;i++){
                temp=temp->next;
            }
            newSNode->next= temp->next;
            temp->next= newSNode;
            length++;

            
        }
        catch(exception & e){
            cout << e.what();
        }
    
}


template <typename T>
void SingleLinkedList<T>::insertEnd(T data){
    

    SNode<T> * newSNode = new SNode<T>();
    newSNode->data= data;
    newSNode->next = nullptr;

    // case of empty linked list
    if(head==nullptr){
        head= newSNode;
        length++;
        return;
    }

    // case of no empty LL
    SNode<T> * temp = head;

    while(temp->next != nullptr){
        temp=temp->next;
    }

    temp->next = newSNode;
    length++;

    

}



template <typename T>
void SingleLinkedList<T>::deleteFront(){
    try{
        if(length==0) throw invalid_argument("list is empty");

        SNode<T>* temp = head;

        head=head->next;
        
        delete temp;

        length--;
    }catch(exception &e){
        cout << e.what();
    }
}


template <typename T>
void SingleLinkedList<T>::deleteEnd(){
    try{
         if(head == nullptr){
            cout << "list is empty" << endl;
            return;
         }

        SNode<T> *temp = head;
        

        if(length==1){
            delete head;
            head= nullptr;
            length--;
            return;
        }

        SNode<T> *prev = nullptr;
        while(temp ->next!= nullptr){
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        delete temp;
        length--;

        

    }catch(exception &e){
        cout << e.what() << endl;
    }

}


template <typename T>
void SingleLinkedList<T>::deleteByValue(T data){
    try{
        if(head == nullptr){
            throw invalid_argument("list is empty");
            return;
        }


        if(head->data== data){
            SNode<T> *temp = head;
            head = head->next;
            delete temp;
            length--;
            return;
        }


        
        SNode<T>*prev = head;
        SNode<T>* temp = head->next;

        while(temp != nullptr &&temp->data != data){
            prev= temp;
            temp= temp->next;
        }

        if(temp == nullptr){
            cout << -1 ;
            return ;
        }

        prev->next= temp->next;
        delete temp;
        length--;

    }catch(exception &e){
        cout << e.what() << endl;
    }
}


template <typename T>
void SingleLinkedList<T>::deleteByPosition(int position){

    try{
        if(position <0 || position >= length){
            throw invalid_argument("invalid position");
        }

        if(head==nullptr){
            cout << "Empty List" << endl;
            return;
        }

        if(position==0){
            deleteFront();
            return ;
        } 

        if(position==length-1 & length-1 !=0){
            deleteEnd();
            return;
        }

        SNode<T>* temp = head;
        SNode<T>* prev = temp;

        for(int i=0;i<position;i++){
            prev= temp;
            temp=temp->next;
        }

        prev->next = temp->next;
        delete temp;
    }
    catch(exception &e ){
        cout << e.what(); 
    }

}




template <typename T>
void SingleLinkedList<T>::print(){
    try{
        if(head==nullptr) {
            cout << "empty list " << endl;
            return;
        }

        SNode<T> *temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp= temp->next;
        }
        cout << endl;
    }catch(exception &e){
        cout << e.what() << endl;
    }
    

}



template <typename T>
SingleLinkedList<T>::~SingleLinkedList(){
    SNode<T>* temp = head;
    while (temp != nullptr) {
        SNode<T>* next = temp->next;
        delete temp;
        temp = next;
    }
   
}