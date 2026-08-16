#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 190. Reverse Bits
Difficulty: Easy
Topic: Bit Manipulation

Brute Force Approach:
- Extract each bit from the input number starting from the least
  significant bit.
- Place each extracted bit into the result from left to right.
- Since the integer contains exactly 32 bits, repeat the process
  32 times.

Time Complexity: O(32) ≈ O(1)
Space Complexity: O(1)

Optimal Approach:
- Extract the last bit of n using (n & 1).
- Shift result left by one position to make space for the new bit.
- Add the extracted bit to result using OR.
- Shift n right to process the next bit.
- Repeat for all 32 bits.

Time Complexity: O(32) ≈ O(1)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/reverse-bits/
-------------------------------------------------------
*/

class Solution {
public:
    int reverseBits(int n) {

        int result = 0;

        // Process all 32 bits
        for (int i = 0; i < 32; i++) {

            // Extract the last bit of n
            int bit = n & 1;

            // Shift result left to make space for the new bit
            result = result << 1;

            // Add the extracted bit to result
            result = result | bit;

            // Remove the processed bit from n
            n = n >> 1;
        }

        return result;
    }
};