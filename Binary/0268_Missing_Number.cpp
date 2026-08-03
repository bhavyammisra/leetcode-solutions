#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 268. Missing Number
Difficulty: Easy
Topic: Arrays, Bit Manipulation, Math

Brute Force Approach:
- For every number from 0 to n, search for it in the array.
- Return the number that is not found.

Time Complexity: O(n²)
Space Complexity: O(1)

Better Approach (Hashing):
- Create a boolean array or hash set to mark the numbers present.
- Traverse from 0 to n and return the number that is unmarked.

Time Complexity: O(n)
Space Complexity: O(n)

Optimal Approach (Mathematical Formula):
- The expected sum of numbers from 0 to n is:
      n × (n + 1) / 2
- Calculate the actual sum of the given array.
- The missing number is the difference between the expected and actual sums.

Time Complexity: O(n)
Space Complexity: O(1)

Alternative Optimal Approach:
- XOR all numbers from 0 to n.
- XOR all elements of the array.
- The remaining value is the missing number.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/missing-number/
-------------------------------------------------------
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        // Expected sum of numbers from 0 to n
        int expected = n * (n + 1) / 2;

        // Actual sum of elements in the array
        int actual = 0;

        for (int num : nums) {
            actual += num;
        }

        // The difference is the missing number
        return expected - actual;
    }
};