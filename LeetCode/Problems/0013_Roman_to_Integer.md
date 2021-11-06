Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

      Symbol       Value
      I             1
      V             5
      X             10
      L             50
      C             100
      D             500
      M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:
```
Input: s = "III"
Output: 3
```
Example 2:
```
Input: s = "IV"
Output: 4
```
Example 3:
```
Input: s = "IX"
Output: 9
```
Example 4:
```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

```
Example 5:
```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 ```

Constraints:
```
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
```


## Solution 1 :

Create a map with string as the key and corresponding interger as the value.
(including that of {"IV" : 4}, {"IX" : 9},...)
Initialize a number = 0;
Now traverse the given string from left to right. At each index such that, index < last_index, 
find the substring of length 2 in the map,
-  if found a 2 character substring then add that value to the number;
-  if the 2 char substring is not found then use the single character to add the value.




##  Solution 2 :

Solution-2 is a refinement over solution-1

Create a map with string as the key and corresponding interger as the value.
(including that of {"IV" : 4}, {"IX" : 9},...)
Initialize a number = 0;
Now traverse the given string from left to right. At each index such that, index < last_index, 
check if the roman_to_int[i] < roman_to_int[i+1] 
-  if true the use a 2 character substring to search the map and add that value to the number;
-  if false then use the single character to add the value.

```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInteger = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int num = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (i < s.size() - 1 && romanToInteger[s[i]] < romanToInteger[s[i+1]])
                num -= romanToInteger[s[i]];
            else num += romanToInteger[s[i]];
        }

        return num;
    }
};
```

## Even Better Solution :
Observation : 

Instead of traversing left-to-right, we can traverse right-to-left (i.e. highest index to the lowest index)
While traversing if the numberic equivalent at the current index is less than that of the next higher index
we subtract the current value from the final number otherwise we add the value.


```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> toInt{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
             {'D', 500}, {'M', 1000}
        };
        
        int last = s.length() - 1;
        int num{toInt[s[last]]};
        
        for (int i = last - 1; i >= 0; --i) {
            if (toInt[s[i]] < toInt[s[i + 1]])
                num -= toInt[s[i]];
            else
                num += toInt[s[i]];
        }
        
        return num;
    }
};
```
