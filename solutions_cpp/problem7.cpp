//
//  problem7.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 05/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*
Problem #7 [Medium] : This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <iostream>
#include <vector>

using namespace std;

    int countDecodings(string s, int l, int r, vector<vector<int>>& dp) {
        // if (l > r) return 0;
        if (l >= r) return 1;
        int n = s[l] - '0', count = 0;
        l++;
        while (n <= 26) {
            if (s[l] - '0' == 0) {
                n = n * 10;
                ++l;
                if (n > 20) exit(11);
                else return (dp[l][r] == -1) ? countDecodings(s, l, r, dp) : dp[l][r];
            }
            else {
                if (dp[l][r] == -1) {
                    count = count + countDecodings(s, l ,r, dp);
                    dp[l][r] = count;
                }
                else count += dp[l][r];
                n = n*10 + s[l++] - '0';
            }
        }
        return count;
    }

    int numDecodings(string s) {
        if (s == "" ) return 0;
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size(), -1));
        return countDecodings(s, 0, int(s.size() - 1), dp);
    }

int main(void) {
    cout << numDecodings("1234") << endl;  // 3
    cout << numDecodings("10234") << endl; // 2
    cout << numDecodings("20310234") << endl; // 4
    return 0;
}
