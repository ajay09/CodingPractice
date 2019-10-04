//
//  problem5.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 05/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
Problem #6 [Hard] : This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev
 fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR
 linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node
 at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *dPointer;
    ListNode(int x) : val(x), dPointer(NULL) {}
};

class XORLL{
public:
    int length;
    ListNode* head;
    
    XORLL():length(0), head(NULL){};
    
    bool add(int element) {
        ListNode* temp = this->head;
        ListNode* data = new ListNode(element);
        if (!temp) {
            this->head = data;
            return true;
        }
        ListNode *prev, *next;
        prev = NULL;
        next = (ListNode *)((uintptr_t)temp->dPointer ^ (uintptr_t)prev);
        while (next) {
            prev = temp;
            temp = next;
            next = (ListNode *)((uintptr_t)temp->dPointer ^ (uintptr_t)prev);
        }
        if (temp) {
            temp->dPointer = (ListNode *)((uintptr_t)prev ^ (uintptr_t)data);
            data->dPointer = (ListNode *)((uintptr_t)temp ^ (uintptr_t)NULL);
            return true;
        }
            
        return false;
    }
    
    void print() {
        ListNode *prev, *next, *temp;
        prev = NULL;
        temp = this->head;
        next = (ListNode *)((uintptr_t)temp->dPointer ^ (uintptr_t)prev);
        cout << temp->val << " - ";
        while (next) {
            prev = temp;
            temp = next;
            next = (ListNode *)((uintptr_t)temp->dPointer ^ (uintptr_t)prev);
            cout << temp->val << " - ";
        }
        cout << endl;
    }
    
    ListNode* getNode(int index) {
        ListNode *prev, *next, *temp;
        prev = NULL;
        temp = this->head;
        next = (ListNode *)((uintptr_t)temp->dPointer ^ (uintptr_t)prev);
        --index;
        while (index >= 0) {
            prev = temp;
            temp = next;
            next = (ListNode *)((uintptr_t)temp->dPointer ^ (uintptr_t)prev);
            --index;
        }
        return index >= 0 ? NULL : temp;
    }
};

int main(void) {
    XORLL my;
    my.add(1);
    my.add(2);
    my.add(3);
    my.add(4);
    my.add(5);
    my.add(6);
    my.add(7);
    my.print();
    cout << my.getNode(0)->val << endl;
    cout << my.getNode(3)->val << endl;
    cout << my.getNode(6)->val << endl;
    cout << endl;
    return 0;
}
