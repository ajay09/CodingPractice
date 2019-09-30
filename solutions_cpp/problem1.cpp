//
//  problem1.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 28/09/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//

/*
 Problem #1 [Easy] : This problem was recently asked by Google.
 
 Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 
 Bonus: Can you do this in one pass?
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// single pass solution
bool twoSums(vector<int>& v, int n) {
    unordered_set<int> v_hash;
    int second_number;
    for (int a : v) {
        second_number = n - a;
        auto it = v_hash.find(second_number); /// find in unordered_set is amortised O(1)
        if (it != v_hash.end())
            return true;
        v_hash.insert(a);
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {10, 15, 3, 7};
    
    cout << twoSums(v, 17) << endl;
    cout << twoSums(v, 6) << endl; /// don't accidently consider the same element twice.
    
    return 0;
}
