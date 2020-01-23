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

// Similar :  If the list is already sorted then we can do this using two pointers.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// single pass solution
bool twoSums(vector<int>& nums, int sum) {
    unordered_set<int> numbersSeen; // since we just have to store a hash of values seen hence use unordered set.
                                    // unordered set is also a hash of just keys.
    for (int n : nums) {
        int secondNumber = sum - n;
        if (numbersSeen.find(secondNumber) != numbersSeen.end()) // for the current number check if its complementary
            return true;                                        //  has been appeared in the numbers seen till now ?
        numbersSeen.insert(n);
    }
    
    return false;
}

int main() {
    vector<int> v = {10, 15, 3, 7};
    
    cout << twoSums(v, 17) << endl;
    cout << twoSums(v, 6) << endl; // don't accidently consider the same element twice.
    
    v = {10, 15 , 3, 7, 3};
    cout << twoSums(v, 6) << endl;
    
    return 0;
}
