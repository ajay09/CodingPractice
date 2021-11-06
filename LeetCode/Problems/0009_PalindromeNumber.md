Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
```
Input: 121
Output: true
```
Example 2:
```
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```
Example 3:
```
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

Follow up:
Coud you solve it without converting the integer to a string?

 

Compare the first and the last digit of the number and return false if they don't match.
e.g. 2332 => 2332 / 1000  and 2332 % 10 are equal, thus we proceed for further verification.
And the number in the next iteration will become 33 => 33 / 10 and 33 % 10 are also equal.
Thus we return true.
 

Solution 1 ：
```
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int divisor{1};
        while (num / divisor >= 10) {
            divisor = divisor * 10;
        }
        if (divisor == 1)
            return true;
        while (x) {
            if (x / divisor != x % 10) {
                return false;
            }
            x = (x % divisor) / 10;
            divisor = divisor / 100;
        }
        return true;
    }
};
```
<br>

Clever Solution :

Considering a number as an input, we can imagine 3 possibilities.
- Observation 1 : Negative numbers can't be palindromes. e.g. -11 and 11- are not equal.
- Observetion 2 : A number ending in 0 can't be a palindrome. As that would require the first digit to also be 0 which is not possible. Except the number 0 itself.
- Observation 3 : If a number is a palindrome then the two halves of the number should be equal.
Thus we flip and take out the second half and check if the remaining first half is equal to it or not. To take out the second half we can take the lowest digit of the number every time by taking %10 and add the digit to a reverseNum. Thus every time we take the lowest digit the remaining number must be divided by 10. The loop stops when the reverseNum is greater than or equal to the remaining number. 
    - If it is an even palindrome then the reverseNum should be exactly equal to the remaining number. 
    - If the number is an odd palindrome then the middle digit will be a part of the reverseNum. Thus reverseNum / 10 should be equal to the remaining number.
    - If neither of the above cases then it is not a palindrome.
 

Solution 2 ：
```
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        
        int reverseNum{0};
        while (x > reverseNum) {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        
        return  (reverseNum == x) || ((reverseNum / 10) == x);
    }
};
```



 
Another possible solution :
    
    Reverse the number entirely and check if they are equal. 
    Note that the case where there are chances of overflow, the number won't be a palindrome.

<br>
<br>

https://leetcode.com/problems/palindrome-number/

https://leetcode.com/problems/palindrome-number/discuss/5127/9-line-accepted-Java-code-without-the-need-of-handling-overflow
