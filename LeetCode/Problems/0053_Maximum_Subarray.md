Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```
Example 2:
```
Input: nums = [1]
Output: 1
```
Example 3:
```
Input: nums = [5,4,-1,7,8]
Output: 23
```

Constraints:
```
1 <= nums.length <= 105
-104 <= nums[i] <= 104
```

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

## Solution - 1:
Brute Force : Find all the subarray sums and return the maximum.
```
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int maxSubarray = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int currentSubarray = 0;                 // subarray starting from i
            for (int j = i; j < nums.size(); j++) {  // first subarray is the element i itself.
                currentSubarray += nums[j]; 
                maxSubarray = max(maxSubarray, currentSubarray);
            }
        }
        
        return maxSubarray;
    }
};
```

## Solution 2 :
Kadane's Algo (DP)
When it comes to DP, the first thing for us to figure out is the format of the sub problem(or the state of each sub problem). The format of the sub problem can be helpful when we are trying to come up with the recursive relation.

At first, I think the sub problem should look like: maxSubArray(int A[], int i, int j), which means the maxSubArray for A[i: j]. In this way, our goal is to figure out what maxSubArray(A, 0, A.length - 1) is. However, if we define the format of the sub problem in this way, it's hard to find the connection from the sub problem to the original problem(at least for me). In other words, I can't find a way to divided the original problem into the sub problems and use the solutions of the sub problems to somehow create the solution of the original one.

So I change the format of the sub problem into something like: maxSubArray(int A[], int i), which means the maxSubArray for A[0:i ] which must has A[i] as the end element. Note that now the sub problem's format is less flexible and less powerful than the previous one because there's a limitation that A[i] should be contained in that sequence and we have to keep track of each solution of the sub problem to update the global optimal value. However, now the connect between the sub problem & the original one becomes clearer:

    maxSubArray(A, i) = (maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0)  +  A[i]; 

```
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        int max_sum = dp[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            max_sum = max(dp[i], max_sum);
        }
        
        return max_sum;
    }
};
```

The maximum is initially A[0]. Suppose we've solved the problem for A[1 .. i - 1]; how can we extend that to A[1 .. i]? 
The maximum sum in the first I elements is either the maximum sum in the first i - 1 elements (which we'll call MaxSoFar), 
or it is that of a subvector that ends in position i (which we'll call MaxEndingHere).

MaxEndingHere is either A[i] plus the previous MaxEndingHere, or just A[i], whichever is larger.

Since we only require the previouw MaxEndingHere, so we don't need to maintain the dp array.

```
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_so_far{nums[0]};
        int max_ending_here{nums[0]};
        
        for (int i = 1; i < nums.size(); ++i) {
            max_ending_here = nums[i] + (max_ending_here > 0 ? max_ending_here : 0);
            max_so_far = max(max_ending_here, max_so_far);
        }
        
        return max_sum;
    }
};
```

This can further be modified as
```
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_so_far{nums[0]};
        int max_ending_here{nums[0]};
        
        for (int i = 1; i < nums.size(); ++i) {
            max_ending_here = max(nums[i], nums[i] + max_ending_here);
            max_so_far = max(max_ending_here, max_so_far);
        }
        
        return max_so_far;
    }
};
```


