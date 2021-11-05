//
//  problem_026.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 24/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
 Problem #26 [Medium] : This problem was asked by Google.

 Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

 The list is very long, so making more than one pass is prohibitively expensive.

 Do this in constant space and in one pass.
*/

#include <iostream>
#include <vector>

using namespace std;

struct node{
    int val;
    node *next;
    node(int x) : val(x), next(nullptr) {}
};

void printList(node* head) {
    for (; head; head = head->next) cout << head->val << " - " ; cout << endl;
}

void insert(node*& head, int x) {
    node *curr = head;
    if (!curr) {
        head = new node(x);
        return;
    }
    
    while (curr->next)
        curr = curr->next;
    
    curr->next = new node(x);
}

// given k is less than the length of the list.
// double pass
void deleteK1(node*& head, int k) {
    node *curr = head, *prev;
    int len = 0;
    for (auto temp = head; temp; temp = temp->next) ++len;
    
    prev = nullptr;
    while (len - k > 0) {
        prev = curr;
        curr = curr->next;
        len--;
    }
    
    if (!prev)
        head = head->next;
    else
        prev->next = curr->next;
    delete curr;
}

// single pass
void deleteK2(node*& head, int k) {
    node *curr = head, *kth, *prev;
    while (--k) curr = curr->next;
//    cout << curr->val;
    prev = nullptr;
    kth = head;
    
    while (curr->next) {
        prev = kth;
        kth = kth->next;
        curr = curr->next;
    }
    
    if (!prev)
        head = head->next;
    else
        prev->next = kth->next;
    delete kth;
}

int main() {
    node *head = nullptr;
    insert(head, 3);
    insert(head, 1);
    insert(head, 5);
    insert(head, 4);
    insert(head, 2);
    insert(head, 7);
    insert(head, 9);
    insert(head, 6);
    printList(head);
    deleteK2(head, 2);
    printList(head);
    return 0;
}
