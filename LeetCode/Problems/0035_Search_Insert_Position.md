Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```
Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```
Example 3:
```
Input: nums = [1,3,5,6], target = 7
Output: 4
```
Example 4:
```
Input: nums = [1,3,5,6], target = 0
Output: 0
```
Example 5:
```
Input: nums = [1], target = 0
Output: 0
```

Constraints:
```
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
```


## Approach 1: Binary Search
Intuition

Starting from left = 0 and right = n - 1, we then move either of the pointers according to various situations:

  While left <= right:

  - Pivot index is the one in the middle: pivot = (left + right) / 2.
  - If the target value is equal to the pivot element: target == nums[pivot], we're done.
  - If the target value is less than the pivot element target < nums[pivot], continue to search on the left subarray by moving the right pointer right = pivot - 1.
  - If the target value is greater than the pivot element target > nums[pivot], continue to search on the right subarray by moving the left pointer left = pivot + 1.

  
  What if the target value is not found?

**In that case, the loop will be stopped at the moment when right < left and nums[right] < target < nums[left]. 
Hence, the proper position to insert the target is at the index left.**

```
class Solution {
  public:
  int searchInsert(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return left;
  }
};
```

## Solution - 2 :
while moving low and high indices move low = mid + 1 but move high as high = mid.
If the number is not found then the position to insert is the first number greater than
the target, thus we must always keep the first greater number in our range of search.

In the end if the number at high < target then that means there is no number in the given
array that is greater than the target, thus the target should be inserted after the last element.

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return (nums[high] < target) ? high + 1 : high;
    }
};
```
The above code can be re-written as : 
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        
        return right;
    }
};
``` 


