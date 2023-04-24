//
//  LinkedList-header.h
//  Hello world
//
//  Created by Omar Gomaa on 20/04/2023.
//

#ifndef LinkedList_header_h
#define LinkedList_header_h

#include <iostream>
#include <vector>
using namespace std ;

struct Node {
    int num , counter;
    Node* after;
};

class List {
public:
    List();

    void add(int num);
    void remove(int num);
    void vectorlist(const vector<int>& v);
    void printList() const;
    int getSum() const;
    void insert(int v1, int v2);
    
    

private:
    Node* head;
};



#endif /* LinkedList_header_h */
