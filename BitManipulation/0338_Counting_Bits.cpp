#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 338. Counting Bits
Difficulty: Easy
Topic: Bit Manipulation, Dynamic Programming

Brute Force Approach:
- For every number from 0 to n, count the number of set bits
  by checking each bit individually.

Time Complexity: O(n * 32) ≈ O(n)
Space Complexity: O(1) (excluding the output array)

Optimal Approach (Dynamic Programming):
- Let dp[i] represent the number of set bits in integer i.
- Right shifting i by one (i >> 1) removes the least significant bit.
- The number of set bits in i equals:
      dp[i >> 1] + (i & 1)
- Here:
    - dp[i >> 1] gives the count of set bits after removing the last bit.
    - (i & 1) is 1 if the last bit is set, otherwise 0.

Time Complexity: O(n)
Space Complexity: O(n)

LeetCode:
https://leetcode.com/problems/counting-bits/
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> countBits(int n) {

        // dp[i] stores the number of set bits in i
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Number of set bits in i =
            // Number of set bits in i/2 + Last bit
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};