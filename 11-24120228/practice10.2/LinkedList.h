#pragma once
template <class T>
struct Node{
    T data;
    Node *next;
};
template <class T>
struct List{
    Node<T> *head;
    Node<T> *tail; 
    int size;
    List() : head(nullptr), tail(nullptr), size(0){}
    bool empty(){
        return size == 0;
    }
    bool invalid(int i){
        return i >= 0 and i < size;
    }
    void init(T data){
        size = 1;
        tail = head = new Node<T>{data, nullptr};
    }
    void addhead(T data){
        if(!head)
            return init(data);
        ++ size;
        head = new Node<T>{data, head};
    }
    void addtail(T data){
        if(!head)
            return init(data);
        ++ size;
        tail->next = new Node<T>{data, nullptr};
        tail = tail -> next;
    }
    void insertBef(T data, Node<T> *p){
        if(!p)
            return;
        ++ size;
        Node<T> *temp = new Node<T>();
        *temp = *p;
        *p = {data, temp};
    }
    void addmid(int i, T data){
        if(i < 0 or i > size)
            return;
        if(i == 0)
            return addhead(data);
        if(i == size)
            return addtail(data);
        insertBef(data, getmid(i));
    }
    void removehead(){
        if(!head)
            return;
        -- size;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        temp = nullptr;
    }
    void removetail(){
        if(!head)
            return;
        if(!head -> next)
            return removehead();
        -- size;
        Node<T> *p = head;
        for(; p -> next -> next; p = p -> next);
        delete p -> next;
        p -> next = nullptr;
        tail = p;
    }
    void removemid(int i){
        if(!invalid(i))
            return;
        if(i == 0)
            return removehead();
        if(i == size - 1)
            return removetail();
        Node<T> **p = &head;
        for(; *p and i; p = &(*p) -> next, i --);
        if(*p and !i){
            Node<T> *temp = *p;
            *p = (*p) -> next;
            delete temp;
            temp = nullptr;
            -- size;
        }
    }
    Node<T> *gethead(){
        return head;
    }
    Node<T> *gettail(){
        return tail;
    }
    Node<T> *getmid(int i){
        if(!invalid(i))
            return nullptr;
        Node<T> *p = head;
        for(; p and i; p = p -> next, i --);
        return p;
    }
    Node<T> *getdata(int data){
        Node<T> *p = head;
        for(; p and p -> data != data; p = p -> next);
        return p;
    }
    ~List(){
        for(Node<T> *p = head; p;){
            Node<T> *temp = p -> next;
            delete p;
            p = temp;
        }
        head = tail = nullptr;
        size = 0;
    }
};