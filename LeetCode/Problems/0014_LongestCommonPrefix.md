Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```
Example 2:
```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

Constraints:
```
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
```

## Solution : 1
Vertical Scan, for each position in a string compare the characters at that position for all the strings.

Worst case o(S) where S is the total number of characters from all the strings.

```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        
        for (int col = 0; col < strs[0].size(); ++col) {
            char c = strs[0][col];
            for (int row = 1; row < strs.size(); ++row) {
                if (col >= strs[row].size() || strs[row][col] != c) {
                    return strs[0].substr(0, col);
                }
            }
        }
        
        return strs[0];
    }
};
```

## Solution : 2
If we sort the vector then the most differing strings will be at the two ends. So to get the LCP we just have 
to compare the first and the last string.
