//
//  problem2.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 28/09/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//

/*
Problem #2 [Hard]: This problem was asked by Uber.
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
 
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 
Follow-up: what if you can't use division?
https://leetcode.com/articles/product-of-array-except-self/
 Follow up:
 Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <iostream>
#include <vector>

using namespace std;

//// brute force => O(n^2) | will give Time Limit Exceeded on LeetCode
//vector<int> productExceptSelf(vector<int>& nums) {
//    vector<int> output(nums.size(), 1);
//
//    for (in t i = 0; i < int(nums.size()); ++i) {
//        for(int j = 0; j < int(output.size()); ++j)
//            if (j != i)
//                output[j] = output[j] * nums[i];
//    }
//    return output;
//}

/*
// O(n) without division
// leftProduct contains the product of all the elements left to the current index.
// rightProduct contains the product of all the elements right to the current index.
/// e.g. [3, 4, 5]
/// left product => [1, 3, 12] | there is no element left to 3 so take product of elements left to 3 as 1
/// right product => [20, 5, 1] | there is no element right to 5 so take product of elements left to 5 as 1
/// result => multiply the respective indices of leftProduct & rightProduct [20, 15, 12]

 vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> leftProduct(nums.size(), 0), rightProduct(nums.size(), 0), result;
    
    leftProduct[0] = rightProduct[nums.size()-1] = 1;
    for (int i = 1; i < int(nums.size()); ++i)
        leftProduct[i] = leftProduct[i-1] * nums[i-1];
    for (int i = int(nums.size()) - 2; i >= 0; --i)
        rightProduct[i] = rightProduct[i+1] * nums[i+1];

    for (int i = 0; i < int(nums.size()); ++i)
        result.emplace_back(leftProduct[i] * rightProduct[i]);
    
    
    return result;
}
*/

// O(n) with Constant Space
// We will be using the output array as one of L or R and we will be constructing the other one on the fly.
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    int leftProduct;
    
    result[nums.size()-1] = 1;
    for (int i = int(nums.size()) - 2; i >= 0; --i)
        result[i] = result[i+1] * nums[i+1];
    
    leftProduct = 1;
    for (int i = 0; i < int(nums.size()); ++i) {
        result[i] = leftProduct * result[i];
        leftProduct = leftProduct * nums[i];
    }
    
    
    return result;
}





int main(void) {
    vector<int> v = {1, 2, 3, 4, 5}, res;
    
    res = productExceptSelf(v);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    v = {1,2,3,0,4,5};
    res = productExceptSelf(v);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    v = {0,0}; // [0,0]
    res = productExceptSelf(v);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    v = {1,0}; // [0,1]
    res = productExceptSelf(v);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    v = {3,4,5,6};
    res = productExceptSelf(v);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}
