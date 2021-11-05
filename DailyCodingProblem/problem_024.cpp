//
//  problem_024.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 24/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
 Problem #24 [Medium] : This problem was asked by Google.

 Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

 Design a binary tree node class with the following methods:

 is_locked, which returns whether the node is locked
 lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
 unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
 
 You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
*/

#include <iostream>
#include <vector>

using namespace std;

struct node{
    int val;
    node *left, *right, *parent;
    bool isLocked;
    node(int x) : val(x), isLocked(false), left(nullptr), right(nullptr), parent(nullptr) {}
};

class binaryTree{
public:
    node *head;
    
    binaryTree() {
        head = nullptr;
    }
    
    bool isLocked(node *givenNode) {
        return givenNode->isLocked;
    }
    
    bool lock(node *givenNode) {
        if (!givenNode) return true;
        if !(lock(givenNode->parent) || lock(givenNode->left) || lock(givenNode->right))
            reutrn ;
    }
};
void insert(node*& head, int x) {
    node *curr = head;
    if (!curr) {
        head = new node(x);
        return ;
    }
    
}

int main() {
    return 0;
}
