#include <iostream>
#include <string>
#include "SingleLinkedList.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;
using namespace DataStructures;
int main(){

    SingleLinkedList<int> list;
    
    Stack<int> st;
    Queue<string> q;


    q.push("basem");
    q.push("mohamed");
    q.push("abdelsabor");
    q.push("mahram");


    while(!q.isEmpty()){
        cout<< q.front() << endl;
        q.pop();
    }
    
    cout << q.size();
    

   
}

