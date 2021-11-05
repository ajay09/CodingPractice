//
//  problem4.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 04/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
 Problem #4 [Hard] This problem was asked by Stripe.
 Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
 
 For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
//// Using Hash Table O(n)
int firstMissingPositive(vector<int>& v){
    unordered_map<int, bool> seen;
    int n = int(v.size());
    for (int i = 1; i <= n; ++i)
        seen[i] = false;
    
    for (int num : v)
        seen[num] = true;
    
    int smallestPositive = n + 1;
    for (int i = 1; i <= n; ++i) {
        if (seen[i] == false) {
            smallestPositive = i;
            break;
        }
    }
    return smallestPositive;
}
*/

/*
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
// O(n) time and O(1) space.
int firstMissingPositive(vector<int>& nums) {
    int n = int(nums.size()), index;
    
    for (size_t i = 0; i < n; ++i)
        if (nums[i] > n || nums[i] < 0)
            nums[i] = 0;
    
    for (size_t i = 0; i < n; ) {
        index = nums[i] - 1;
        if (index >= 0 && i != index) {
            if(nums[i] == nums[index]) nums[i] = 0; // to handle duplicate values.
            else swap(nums[i], nums[index]);
        }
        else ++i;
    }
    
    for (int i = 0; i < n; ++i) {
        if(nums[i] == 0) return i + 1;
    }
    return n + 1;
}
 */

// O(n) time O(1) space
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
//  Logic :  If the number is in the range [1, n], where n is the size of the array,
//  then place the number at its natural position in the array i.e. @ index = num - 1
//  Do this by swap(nums[i], nums[nums[i] - 1]) but while doing so ensure that both these numbers
//  are not same. If they are same they skip the swap and simply move to next position as one of them
//  is at its correct position.
// Because an array of size 5 can at max contain 1,2,3,4,5 thus the smallest missing positive no will be 6.
int firstMissingPositive(vector<int>& nums) {
    int n = int(nums.size()), index, smallestPositive;
    
    for (int i = 0; i < n; ) {
        index = nums[i] - 1;
        if (index >= 0 && index < n &&  nums[i] != nums[index])
            swap(nums[i], nums[index]);
        else ++i;
    }
    
    smallestPositive = n + 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }
    
    return smallestPositive;
}

int main(void) {
    vector<int> v;
    
    v = {1, 1};
    cout << firstMissingPositive(v) << endl; // 2
    
    v = {3, 4, -1, 1};
    cout << firstMissingPositive(v) << endl; // 2
    
    v = {1,2,0};
    cout << firstMissingPositive(v) << endl; // 3
    
    v = {};
    cout << firstMissingPositive(v) << endl; // 1
    
    v = {1,2,3};
    cout << firstMissingPositive(v) << endl; // 4
    
    v = {3,1,2};
    cout << firstMissingPositive(v) << endl; // 4
    
    v = {7,8,9,11,12};
    cout << firstMissingPositive(v) << endl; // 1
    
    v = {2,1,1,3,2,4};
    cout << firstMissingPositive(v) << endl; // 5
    
    v = {};
    cout << firstMissingPositive(v) << endl; // 1
    
    return 0;
}
