#pragma once
using namespace std;

struct DNode
{
    int data;
    DNode *next;
    DNode *prev;
};

struct DList{
    DNode *head;
    DNode *tail;
    int size;
    DList() : head(nullptr), tail(nullptr), size(0) {}
    bool ivalid(int i){
        return i >= 0 && i < size;
    }
    bool empty(){
        return size == 0;
    }
    void init(int data){
        head = tail = new DNode{data, nullptr, nullptr};
        size = 1;
    }
    void addhead(int data){
        if(!head)
            return init(data);
        ++ size;
        head = new DNode{data, head, nullptr};
        head->next->prev = head;
        return;
    }
    void addtail(int data){
        if(!tail)
            return init(data);
        ++ size;
        tail = new DNode{data, nullptr, tail};
        tail->prev->next = tail;
        return;
    }
    void removehead(){
        if(!head)
            return;
        DNode *temp = head;
        head = head->next;
        head->prev = nullptr;
        if(!head)
            tail = nullptr;
        delete temp;
        temp = nullptr;
        -- size;
    }
    void removetail(){
        if(!tail)
            return;
        DNode *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        if(!tail)
            head = nullptr;
        delete temp;
        temp = nullptr;
        -- size;
    }
    DNode *getmid(int i){
        if(!ivalid(i))
            return nullptr;
        if(i == 0)
            return head;
        if(i == size - 1)
            return tail;
        if(i < size / 2){
            for(DNode *p = head; p; p = p->next)
                if(i -- == 0)
                    return p;
        }else{
            i = size - i - 1;
            for(DNode *p = tail; p; p = p->prev)
                if(i -- == 0)
                    return p;
        }
        return nullptr;
    }
    void addmid(int i, int data){
        if(i < 0 or i > size)
            return;
        if(i == 0)
            return addhead(data);
        if(i == size)
            return addtail(data);
        DNode *temp = getmid(i);
        if(!temp)
            return;
        DNode *newnode = new DNode{data, temp, temp->prev};
        temp->prev->next = newnode;
        temp->prev = newnode;
        ++ size;
    }
    void add_ascending(int data){
        if(!head)
            return init(data);
        if(head->data > data)
            return addhead(data);
        if(tail->data < data)
            return addtail(data);
        for(DNode *p = head; p; p = p->next)
            if(p->data > data){
                DNode *temp = new DNode{data, p, p->prev};
                p->prev->next = temp;
                p->prev = temp;
                ++ size;
                return;
            }
    }
    void removemid(int i){
        if(!ivalid(i))
            return;
        if(i == 0)
            return removehead();
        if(i == size - 1)
            return removetail();
        DNode *temp = getmid(i);
        if(!temp)
            return;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        temp = nullptr;
    }
    DNode *gethead(){
        return head;
    }
    DNode *gettail(){
        return tail;
    }
    DNode *getdata(int data){
        for(DNode *p = head; p; p = p->next)
            if(p->data == data)
                return p;
        return nullptr;
    }
    ~DList(){
        while(head)
            removehead();
        size = 0;
    }
};