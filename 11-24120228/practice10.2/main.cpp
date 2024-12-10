#include <iostream>
#include "LinkedList.h"
using namespace std;
#include "LinkedList.h"
template <class T>
void copy(List<T> &ls, List<T> &ls2){
    for(Node<T> *p = ls.gethead(); p; p = p -> next)
        ls2.addtail(p -> data);
}
template <class T>
void reverse(List<T> &ls){
    Node<T> *prev = nullptr;
    for(Node<T> *p = ls.gethead(); p;){
        Node<T> *temp = p -> next;
        p -> next = prev;
        prev = p;
        p = temp;
    }
    ls.tail = ls.head;
    ls.head = prev;
}
template <class T>
bool check_symmetric(List<T> &ls){
    int n = ls.size;
    Node<T> *p = ls.gethead();
    for(int i = 0; i < n / 2; i ++){
        Node<T> *q = ls.getmid(n - i - 1);
        if(p -> data != q -> data)
            return false;
        p = p -> next;
    }
    return true;
}
template <class T>
void remove_k_nodes(List<T> &ls, int k){
    Node<T> *p = ls.gethead();
    for(int i = 0; i < ls.size - k - 1; i ++)
        p = p -> next;
    Node<T> *temp = p -> next;
    p -> next = nullptr;
    for(; temp;){
        Node<T> *q = temp -> next;
        delete temp;
        temp = q;
    }

    ls.size -= k;
    ls.tail = p;
    if(!ls.size)    
        ls.head = nullptr;
}
template <class T>
void add_ascending(List<T> &ls, T data){
    if(!ls.head)
        return ls.init(data);
    if(ls.head -> data > data)
        return ls.addhead(data);
    if(ls.tail -> data < data)
        return ls.addtail(data);
    Node<T> *p = ls.gethead();
    for(; p -> next and p -> next -> data < data; p = p -> next);
    ls.insertBef(data, p);
}
template <class T>
void remove_duplicates(List<T> &ls){
    Node<T> *p = ls.gethead();
    for(int i = 0; p; p = p -> next, i++){
        Node<T> *q = p -> next;
        int j = i + 1;
        while(q){
            if(q -> data == p -> data){
                ls.removemid(j);
                q = p -> next;
            } else {
                q = q -> next;
                j++;
            }
        }
    }
}
int main(){
    // DEMO
    List <int> ls;
    add_ascending(ls, 1);
    add_ascending(ls, 1);
    add_ascending(ls, 1);
    // remove_duplicates(ls);
    // reverse(ls);
    // cout << check_symmetric(ls) << endl;
    remove_k_nodes(ls, 3);
    cout << ls.size << endl;
    for(Node<int> *p = ls.gethead(); p; p = p -> next)
        cout << p -> data << ' ';
    ls.~List();
}