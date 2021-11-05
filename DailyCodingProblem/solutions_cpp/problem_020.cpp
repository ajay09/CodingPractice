//
//  problem_020.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 25/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
 Problem #20 [Easy] : This problem was asked by Google.

 Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

 For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

 In this example, assume nodes with the same value are the exact same node objects.

 Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

#include <iostream>
#include <vector>

using namespace std;

struct node{
    int val;
    node *next;
    node(int x) : val(x), next(nullptr) {}
};

void print(node* head) {
    for (; head; head = head->next) cout << head->val << " - "; cout << endl;
}

void insert(node*& head, int x) {
    if (!head) {
        head = new node(x);
        return ;
    }
    node *curr = head;
    while (curr->next) curr = curr->next;
    curr->next = new node(x);
}

// connect list a to node with value x in node b
void connectList(node *a, node *b, int x) {
    while (a->next) a = a->next;
    while (b->next && b->val != x) b = b->next;
    a->next = b;
}

node* findIntersection(node* a, node *b){
    int lenA, lenB, diff;
    lenA = lenB = 0;
    for (auto temp = a; temp; temp = temp->next) ++lenA;
    for (auto temp = b; temp; temp = temp->next) ++lenB;
    if (lenB < lenA) swap(a, b);
    node *currA = a, *currB = b;
    diff = abs(lenB-lenA);
    while (diff > 0) {
        currB = currB->next;
        --diff;
    }
    while (currA->next && currB->next && currA != currB) {
        currA = currA->next;
        currB = currB->next;
    }
    return currA;
}

int main() {
    node *a, *b;
    a = b = nullptr;
    insert(a, 3);
    insert(a, 7);
    insert(b, 99);
    insert(b, 5);
    insert(b, 2);
    insert(b, 1);
    insert(b, 8);
    insert(b, 10);
    connectList(a, b, 8);
    insert(b,15);
    print(a);
    print(b);
    
    cout << findIntersection(a, b)->val << endl;
    return 0;
}
