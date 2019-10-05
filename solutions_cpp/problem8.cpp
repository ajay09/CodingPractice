//
//  problem8.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 05/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*This problem was asked by Google.
 
 A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
 
 Given the root to a binary tree, count the number of unival subtrees.
 
 For example, the following tree has 5 unival subtrees:
 
          0
         / \
        1   0
           / \
          1   0
         / \
        1   1
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, bool> countUnivalTrees(TreeNode* root) {
    if (!root->left && !root->right) return make_pair(1, true);
    
    pair<int, bool> left(0, false), right(0, false), current(0, false);
    if (root->left) left = countUnivalTrees(root->left);
    if (root->right) right = countUnivalTrees(root->right);
    current.first += left.first + right.first;
    if (left.second && right.second && (root->left->val == root->val) && (root->right->val == root->val)) {
        current.first += 1;
        current.second = true;
    }
    else if (!root->left && right.second && (root->right->val == root->val)) {
        current.first += 1;
        current.second = true;
    }
    else if (!root->right && left.second && (root->left->val == root->val)) {
        current.first += 1;
        current.second = true;
    }
    return current;
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }
    
    string item;
    stringstream ss;
    ss.str(input);
    
    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main(void) {
    string input;
    
    input = "[5,1,5,5,5,null,5]";
    cout << countUnivalTrees(stringToTreeNode(input)).first << endl; // 4
    
    input = "[1,2,3,4,5]";
    cout << countUnivalTrees(stringToTreeNode(input)).first << endl; // 3
    
    input = "[2,2,2,5,2]";
    cout << countUnivalTrees(stringToTreeNode(input)).first << endl; // 3
    
    input = "[1,1,1,1,1,null,1]";
    cout << countUnivalTrees(stringToTreeNode(input)).first << endl; // 6

    
    return 0;
}
