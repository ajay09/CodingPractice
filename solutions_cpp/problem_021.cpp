//
//  problem_021.cpp
//  dailyCodingPractice
//
//  Created by Ajay Singh on 25/10/19.
//  Copyright © 2019 Ajay Singh. All rights reserved.
//
/* Problem #21 [Easy] : This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int classroomRequired(vector<vector<int>> vec) {
    set<int> occupied;
    int maxSize = 0, size = 0;
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (!occupied.empty() && *(occupied.begin()) < (*it)[0]) {
            occupied.erase(occupied.begin());
            --size;
        }
        occupied.insert((*it)[1]);
        ++size;
        maxSize = max(maxSize, size);
    }
    return maxSize;
}

int main() {
    vector<vector<int>> vec = {{30, 75}, {0, 50}, {60, 150}};
    cout << classroomRequired(vec) << endl;
    
    vec = {{6, 8}, {5, 8}};
    cout << classroomRequired(vec) << endl;
    
    vec = {{0,30},{5,10},{15,20}};
    cout << classroomRequired(vec) << endl;
    
    return 0;
}
