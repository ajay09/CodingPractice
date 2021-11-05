//
//  problem_011.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 17/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
Problem #11 [Medium] This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible
query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct node{
    bool isWord;
    unordered_map<char, node*> character;
};

node* getNode() {
    node* newNode = new node;
    newNode->isWord = false;
    return newNode;
}

void insert(node* head, string key) {
    node* curr = head;
    
    for (char k : key) {
        auto it = curr->character.find(k);
        if (it == curr->character.end())
            curr->character[k] = getNode();
        curr = curr->character[k];
    }
    
    curr->isWord = true;
}

void complete(node *curr, vector<string>& s, string& word) {
    if (!curr) return;
    if (curr->isWord)   s.push_back(word);
    
    for (auto it = curr->character.begin(); it != curr->character.end(); ++it) {
        word.push_back(it->first);
        complete(it->second, s, word);
        word.pop_back(); // after exploring one child of the curr move to the next child.
    }
}

vector<string> autoComplete(node *head, string key) {
    vector<string> result;
    vector<string> s;
    string word;
    node* curr = head;
    
    for (char k : key) {
        auto it = curr->character.find(k);
        if (it == curr->character.end())
            return result;
        curr = curr->character[k];
    }
    
    for (auto it = curr->character.begin(); it != curr->character.end(); ++it) {
        word = "";
        word += it->first;
        complete(it->second, s, word);
        for (string r : s) result.push_back(key + r);
        s.clear();
    }
    
    return result;
}

bool search(node* head, string key) {
    if (!head) return false;
    node* curr = head;
    
    for (char k : key) {
        auto it = curr->character.find(k);
        if (it == curr->character.end()) return false;
        curr = curr->character[k];
    }
    
    return curr->isWord;
}

int main() {
    node* head = getNode();
    vector<string> result;
    insert(head, "ajay");
    insert(head, "a");
    insert(head, "aj");
    insert(head, "ajaysingh");
    
    cout << search(head, "ajay") << endl;
    cout << search(head, "ajays") << endl;
    cout << search(head, "aj") << endl;
    
    result = autoComplete(head, "a");
    for (string r : result) cout << r << " "; cout << endl;
    
    vector<string> dict = {"dog", "deer", "deal"};
    for (string s : dict) insert(head, s);
    result = autoComplete(head, "de");
    for (string r : result) cout << r << " "; cout << endl;
    
    dict = {"i love you", "island","ironman", "i love leetcode"};
    for (string s : dict) insert(head, s);
    result = autoComplete(head, "ia");
    for (string r : result) cout << r << " "; cout << endl;
    
    return 0;
}
