//
//  problem3.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 30/09/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
 Problem #3 [Medium] This problem was asked by Google.
 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 
 Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
 Example:
            1
           / \
          2   3
             / \
            4   5
 
 as "[1,2,3,null,null,4,5]"
 */


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        queue<TreeNode*> nodeQueue;
        TreeNode* temp;
        vector<string> result;
        
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            temp = nodeQueue.front();
            if (temp != NULL) {
//                cout << temp->val << endl;
                result.push_back(to_string(temp->val));
            }
            else result.push_back("null");
            if (temp) nodeQueue.push(temp->left);
            if (temp) nodeQueue.push(temp->right);
            nodeQueue.pop();
        }
        string s = result.back();
        while (s == "null") {
            result.pop_back();
            s = result.back();
        }
//        copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
//        cout << endl;
        string result_string = "[";
        for (string s : result)
            result_string += s + ",";
        result_string.pop_back();
        result_string += "]";
//        cout << endl << result_string << endl;
        return result_string;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // [1,2,3,null,null,4,5]
        data = data.substr(1, data.size() - 2); // 1,2,3,null,null,4,5

        vector<string> tokens; // Vector to hold our words
        stringstream ss(data);
        string buff;
        while (getline(ss, buff, ','))
            tokens.push_back(buff);

        TreeNode* root = new TreeNode(stoi(tokens[0])), *temp;
        queue<TreeNode*> nodeQueue;
        auto it = tokens.begin() + 1;
        nodeQueue.push(root);
        while (!nodeQueue.empty() && it != tokens.end()) {
            temp = nodeQueue.front();
            temp->left = (*it != "null") ? new TreeNode(stoi(*it)) : NULL;
            ++it;
            if (temp->left) nodeQueue.push(temp->left);
            if (it == tokens.end()) break;
            temp->right = (*it != "null") ? new TreeNode(stoi(*it)) : NULL;
            ++it;
            if (temp->right) nodeQueue.push(temp->right);
            nodeQueue.pop();
        }

        return root;
        
    }
};


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
    string line;
    TreeNode* root = stringToTreeNode("[1,-1,2,-2]");
//    TreeNode* root = stringToTreeNode("[1,2,3,null,null,4,5]"); // cin <=> [1,2,3,null,null,4,5]
//    cout << root->val << endl;
    
    Codec codec;
    root = codec.deserialize(codec.serialize(root));
    string ret = codec.serialize(root);
    
    string out = (ret);
    cout << out << endl;
    
    return 0;
}
