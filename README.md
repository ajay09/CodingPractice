# Daily Coding Practice

My Solutions to Daily Coding Problems from <http://www.dailycodingproblem.com>

***

### Problem 1
Given a list of numbers, return whether any two sums to k. For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?

[Solution.cpp](https://github.com/ajays3/dailyCodingPractice/blob/master/solutions/problem1.cpp "Problem-1 Solution") [Solution.py](https://github.com/ajays3/dailyCodingPractice/blob/master/solutions_py/problem1.py)

---

### Problem 2
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division? And in constant space.

[Solution.cpp](https://github.com/ajays3/dailyCodingPractice/blob/master/solutions_cpp/problem2.cpp) [Solution.py](https://github.com/ajays3/dailyCodingPractice/blob/master/solutions_py/problem2.py)

---

### Problem 3
This problem was asked by Google.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
 Example:
 

            1           
           / \
          2   3
             / \
            4   5


 as "[1,2,3,null,null,4,5]"

[Solution.cpp]() [Solution.py]()

---

### Problem 4
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
 
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

[Solution.cpp]() [Solution.py]()

---

### Problem 5

[Solution.cpp]() [Solution.py]()

---

### Problem 6
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. 
Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node
 at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.

[Solution.cpp]() [Solution.py]()

---

### Problem 7
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

[Solution.cpp]() [Solution.py]()

---