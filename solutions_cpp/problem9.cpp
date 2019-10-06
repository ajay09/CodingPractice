//
//  problem9.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 06/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
 Problem #9 [Hard] : This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>

using namespace std;

//O(n) Iterative Solution
int largestNonAdjacentSum(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 2) nums[0] = max(nums[0], nums[1]);
    
    int n = int(nums.size()), prevMax;
    for (int i = n - 2; i >= 0; --i) {
//        for (int j = i + 2; j < n; ++j) {
        //            prevMax = max(prevMax, nums[j]);          [36 35 34 28 22 25 21 18 20 16 13 5 7]
//        }
        prevMax = (i+2 < n) ? nums[i+2] : 0;
        nums[i] = max(nums[i] + prevMax, nums[i+1]);
    }
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return nums[0];
}


/*
// O(n) solution using dp
int maxSum(vector<int>& nums, int l, int r, vector<int>& dp) {
    if (l > r) return 0;
    if (l+1 >= r) {
        dp[l] = max(nums[l], nums[r]); // when l == r and l+1 == r
        return dp[l];
    }
    if(dp[l] == -1)
        dp[l] = max((nums[l] + maxSum(nums, l+2, r, dp)), (nums[l+1] + maxSum(nums, l+3, r, dp)));
    return dp[l];
}

int largestNonAdjacentSum(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    int largest = maxSum(nums, 0, int(nums.size() - 1), dp);
    copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return largest;
}
//    [36 -1 34 28 25 25 21 20 20 16 13 7 7 ]
//    [10 -1 5 5]
 //*/

int main(void) {
    vector<int> v = {2,7,9,3,1,5,1,2,7,9,6,5,7};
    
    cout << largestNonAdjacentSum(v) << endl;
    
    v = {5,1,1,5};
    cout << largestNonAdjacentSum(v) << endl;
    
    v = {9, 0, 0, 9};
    cout << largestNonAdjacentSum(v) << endl;
    
    return 0;
}

// https://leetcode.com/problems/house-robber/


/*
// Solution Development  starting from Recursion -> DP -> Iterative
https:leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.

class Solution {
public:
    // Iterative solution => 0 ms, faster than 100.00% of C++ online submissions for House Robber.
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 2) nums[0] = max(nums[0], nums[1]);
        
        int n = int(nums.size()), prevMax;
        for (int i = n - 2; i >= 0; --i) {
            prevMax = (i+2 < n) ? nums[i+2] : 0;
            nums[i] = max(nums[i] + prevMax, nums[i+1]);
        }
        return nums[0];
    }
};

 class Solution {
 public:
 // Iterative solution => 0 ms, faster than 100.00% of C++ online submissions for House Robber.
    int rob(vector<int>& nums) {
        int n = nums.size(), prevMax;
        for (int i = n - 1; i >= 0; --i) {
            prevMax = 0;
            for (int j = i + 2; j < n; ++j) {
                prevMax = max(prevMax, nums[j]);
            }
            nums[i] = nums[i] + prevMax;
        }
        return nums.size() ? *max_element(nums.begin(), nums.end()) : 0;
    }
 };

 class Solution {
 public:
 // Normal recursion gave TLE. Trying DP. => 0 ms, faster than 100.00% of C++ online submissions for House Robber.
    int maxMoney(vector<int>& nums, int l, int r, vector<int>& dp) {
        if (l > r) return 0;
        if (l+1 >= r) {
            dp[l] = max(nums[l], nums[r]); // when l == r and l+1 == r
            return dp[l];
        }
        if(dp[l] == -1)
            dp[l] = max((nums[l] + maxMoney(nums, l+2, r, dp)), (nums[l+1] + maxMoney(nums, l+3, r, dp)));
        return dp[l];
    }
 
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return maxMoney(nums, 0, nums.size() - 1, dp);
    }
 };
 
 */
