//
//  main.cpp
//  Hello world
//
//  Created by Omar Gomaa on 16/03/2023.
//

#include "LinkedList-header.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v;

    cout << "insert number of values "; // user enters amount of values
    cin >> n;

    cout << "insert " << n << " values: "; // user inserts content of values
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);  // to insert nuber
    }

    List list;
    list.vectorlist(v);

    int v1, v2;
    cout << "Insert value 1: ";
    cin >> v1;
    cout << "Insert value 2: ";
    cin >> v2;
    list.insert(v1, v2);
    cout << "Linked list: ";
    list.printList();
    int sum = list.getSum();
    cout << "Sum of nodes: " << sum << endl;

    return 0;
}

List::List() {
    head = nullptr;
}

void List::add(int num) {
    Node* newNode = new Node;
    newNode->num = num;
    newNode->counter = 1;
    newNode->after = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->after != nullptr) {
            current = current->after;
        }
        current->after = newNode;
    }
}

void List::remove(int num) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->num != num) {
        prev = current;
        current = current->after;
    }

    if (current == nullptr) {
        return;
    }

    if (current->counter > 1) {
        current->counter--;
        return;
    }

    if (prev == nullptr) {
        head = current->after;
    } else {
        prev->after = current->after;
    }

    delete current;
}



int List::getSum() const {
    Node* current = head;
    int sum = 0;
    while (current != nullptr) {
        sum += current->num * current->counter;
        current = current->after;
    }
    return sum;
}

void List::vectorlist(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        int num = v[i];
        Node* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->num == num) {
                current->counter++;
                found = true;
                break;
            }
            current = current->after;
        }
        if (!found) {
            add(num);
        }
    }
}

void List::printList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->num << "(" << current->counter << ") ";
        current = current->after;
    }
    cout << endl;
}

void List::insert(int v1, int v2) {
    Node* current = head;
    while (current != nullptr) {
        if (current->num == v1) {
            Node* newNode = new Node;
            newNode->num = v2;
            newNode->counter = 1;
            newNode->after = current->after;
            current->after = newNode;
            current = newNode->after;
        } else {
            current = current->after;
        }
    }
}

