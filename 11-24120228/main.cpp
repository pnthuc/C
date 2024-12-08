#include <iostream>
using namespace std;
#include <list>
            a
struct DNode
{
    int data;
    DNode *next;
    DNode *prev;
};

struct DList
{
    DNode *head;
    DNode *tail;
    DList() : head(nullptr), tail(nullptr) {}
    void AddHead(int a){
        head = new DNode{a, head, nullptr};
        if(head -> next)
            head -> next -> prev = head;
    }
    void AddTail(int a){
        tail = new DNode{a, nullptr, tail};
        if(tail -> prev)
            tail -> prev -> next = tail;
    }
    void AddMid(int i, int a){
        for(DNode *p = head; p; p = p->next)
            if (-- i == 0){
                p = new DNode{a, p};
            }
    }
    void RemoveHead(){
        if(!head) return;
        DNode *p = head = head->next;
        delete p;
    }
    void RemoveTail(){
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        DNode *p = head;
        while (p->next != tail)
            p = p->next;
        delete tail;
        tail = p;
        tail->next = nullptr;
    }
    void RemoveMid(int a){
        DNode *p = head;
        while (p->next->data != a)
        {
            p = p->next;
        }
        DNode *q = p->next;
        p->next = q->next;
        delete q;
    }
    void RemoveAll(){
        DNode *p;
        while (head)
            p = head = head->next, delete p;
        tail = nullptr;
    }
    DNode *FindI(int i){
        DNode *p = head;
        for (int j = 0; j < i; j++)
            p = p->next;
        return p;
    }
    DNode *FindData(int data){
        DNode *p = head;
        while (p && p->data != data)
            p = p->next;
        return p;
    }


};
int main()
{
    DList ls;
    ls.head = nullptr;
    ls.tail = nullptr;
    ls.AddTail(1);
    ls.AddTail(2);
    ls.AddMid(1, 3);
    cout << "List: ";
    ls.RemoveAll();
    ls.AddHead(1);
    ls.AddHead(2);
    ls.AddHead(3);
    ls.AddHead(4);
    ls.RemoveHead();
    ls.RemoveTail();
    DNode * p = ls.FindI(1);
    cout << p->data << endl;
    for(DNode *p = ls.head; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
}
