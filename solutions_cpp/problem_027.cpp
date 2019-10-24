//
//  problem_027.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 24/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
Problem #27 [Easy] : This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
 
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    unordered_map<char, char> match;
    stack<char> st;
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';
    
    for (char c : s) {
        auto it = match.find(c); // if c is a closing bracket || if(c==')' || c==']' || c=='}')
        if (it != match.end()) {
            if (st.empty() || (match[c] != st.top())) return false;
            st.pop();
        }
        else st.push(c);
    }
    return st.empty();  // true if stack is empty else false
}

int main() {
    string s = "([])[]({})";
    
    s = isValid(s) ? "true" : "false";
    cout << s << endl;
    
    s = "([)]";
    s = isValid(s) ? "true" : "false";
    cout << s << endl;
    
    s = "((()";
    s = isValid(s) ? "true" : "false";
    cout << s << endl;
    
    return 0;
}
