#include "DList.h"
#include <iostream>
using namespace std;
/*
head                    pointer to the head of the list
tail                    pointer to the tail of the list
size                    number of nodes in the list
init(int data)          initializes the list with a node with data
empty()                 returns true if the list is empty
ivalid(int i)           returns true if i is a valid index of the list
addhead(int data)       adds a new node with data to the head of the list
addtail(int data)       adds a new node with data to the tail of the list
addmid(int i, int data) adds a new node with data at index i of the list
add_ascending(int data) adds a new node with data in ascending order
removehead()            removes the head of the list
removetail()            removes the tail of the list
removemid(int i)        removes the node at index i of the list
gethead()               returns the data of the head of the list
gettail()               returns the data of the tail of the list
getmid(int i)           returns the data of the node at index i of the list
~DList()                deletes all nodes in the list
*/
int main(){
    // DEMO
    DList ls;
    ls.addhead(1);
    ls.addhead(2);
    ls.addhead(3);
    ls.addhead(4);
    ls.addtail(3);
    ls.addtail(4);
    ls.addmid(2, 5);
    ls.addmid(0, 6);
    ls.addmid(5, 7);
    ls.addmid(9, 8);
    // 6 4 3 5 2 7 1 3 4 8
    ls.removehead();
    ls.removetail();
    ls.removemid(2);
    cout << ls.size << endl;
    for(int i = 0; i < ls.size; i ++)
        cout << ls.getmid(i) -> data << " ";
    ls.~DList();
    
}