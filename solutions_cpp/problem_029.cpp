//
//  problem_029.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 26/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/*Problem #29 [Easy] : This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encode(string input) {
    string result = "";
    input.push_back(' ');  // to handle the last case
    
    for (int read = 1, prev = 0, count = 1; read < int(input.size()); ++read, ++count) {
        if (input[read] != input[prev]) {
            result += to_string(count) + input[prev];
            count = 0;
        }
        prev = read;
    }
    return result;
}

string decode(string input) {
    string result = "";
    
    for (int read = 0, times = 0; read < (int)input.size(); ) {
        times = 0;
        while (input[read] >= '0' && input[read] <= '9') times = times * 10 + (input[read++] - '0');
        while (times-- > 0) result += input[read];
        ++read;
    }
    return result;
}

int main() {
    string s = "AAAABBBCCDAA";
    
    cout << encode(s) << endl;
    cout << (s == decode(encode(s))) << endl;
    
    s = "ABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC";
    cout << encode(s) << endl;
    cout << (s == decode(encode(s))) << endl;
    
    return 0;
}
