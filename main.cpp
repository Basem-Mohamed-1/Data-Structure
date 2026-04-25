#include <iostream>
#include <string>
#include "SingleLinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;
int main(){

    SingleLinkedList<int> list;
   
    
    DoublyLinkedList<string> dlist;

    cout << dlist.isEmpty() << endl;
    dlist.insertEnd("basem");
    dlist.insertEnd("karem");
    dlist.insertEnd("mohamed");
    dlist.insertEnd("salma");
    dlist.insertStart("im_first");
    dlist.insertByPosition("salem",10) ;
    cout << "This is the size of the list "<<dlist.Dsize() << endl;
    dlist.insertByPosition("shokry",dlist.Dsize());
    dlist.insertByPosition("a7a",0);
    dlist.insertByPosition("mashy",3);
    dlist.deleteStart();
    dlist.deleteStart();
    dlist.deleteEnd();
    dlist.deleteByPosition(4);
    dlist.deleteByPosition(2);
    dlist.deleteByValue("mashy");
    dlist.insertByPosition("mashy",2);
    dlist.insertByPosition("mashy",2);
    dlist.insertByPosition("mashy",2);
    dlist.deleteByValue("mashy");
    cout << dlist.front() << endl;
    cout << dlist.back() << endl;
    cout << dlist.Dsize() << endl;

    dlist.traverseForword();

   


    

    
}

