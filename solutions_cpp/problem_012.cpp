//
//  problem_012.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 09/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
Problem #12 [Hard] : This problem was asked by Amazon.
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

#include <iostream>
#include <vector>

using namespace std;

void uniqueWays(int n, int& ways){
    if (n < 0) return;
    if (n==0) {
        ways++;
        return;
    }
    uniqueWays(n - 1, ways);
    uniqueWays(n - 2, ways);
}

int uniqueWays(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return uniqueWays(n - 1) + uniqueWays(n - 2);
}

int uniqueWays(int n, vector<int>& memo) {
    if (n < 0) return 0;
    if (n == 0) {
        memo[n] = 1;
        return memo[n];
    }
    int ways = 0;
    if (n-1 >= 0 && memo[n - 1] != -1) ways = memo[n-1];
    else
        ways = uniqueWays(n - 1, memo);
    if (n-2 >= 0 && memo[n - 2] != -1) ways += memo[n-2];
    else
        ways += uniqueWays(n - 2, memo);
    memo[n] = ways;
    return memo[n];
}

int uniqueWays(int n, vector<int> X, vector<int> memo) {
    if (n < 0) return 0;
    if (n == 0) {
        memo[n] = 1;
        return memo[n];
    }
    int ways = 0;
    for (int x : X) {
        if (n-x >= 0 && memo[n - x] != -1) ways += memo[n-x];
        else ways += uniqueWays(n, X, memo);
    }
    memo[n] = ways;
    return memo[n];
}

int main() {
    int staircase = 400;
//    int ways = 0;
//    uniqueWays(staircase, ways);
//    cout << ways << endl;
//    cout << uniqueWays(staircase) << endl;
    vector<int> memo(staircase+1, -1);
    cout << uniqueWays(staircase, memo) << endl;
    
    vector<int> X = {1, 2};
    memo.resize(staircase+1, -1);
    cout << uniqueWays(staircase, X, memo) << endl;
    return 0;
}
