#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 217. Contains Duplicate
Difficulty: Easy
Topic: Arrays, Hashing

Brute Force Approach:
- Compare every element with every other element.
- If any two elements are equal, return true.
- Otherwise, return false.

Time Complexity: O(n²)
Space Complexity: O(1)

Optimal Approach:
- Use an unordered_set to keep track of elements already seen.
- Traverse the array once.
- If the current element already exists in the set, a duplicate is found.
- Otherwise, insert the element into the set and continue.

Time Complexity: O(n)
Space Complexity: O(n)

LeetCode:
https://leetcode.com/problems/contains-duplicate/
-------------------------------------------------------
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            // If the number already exists in the set,
            // a duplicate has been found.
            if (seen.count(num))
                return true;

            // Store the current number.
            seen.insert(num);
        }

        return false;
    }
};