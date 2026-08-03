#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 191. Number of 1 Bits
Difficulty: Easy
Topic: Bit Manipulation

Brute Force Approach:
- Traverse each of the 32 bits of the integer.
- Check whether each bit is set (1) using bitwise operations.
- Count the total number of set bits.

Time Complexity: O(32) ≈ O(1)
Space Complexity: O(1)

Optimal Approach (Bit Manipulation):
- Repeatedly check the least significant bit (LSB).
- Add it to the count if it is set.
- Right shift the number by one bit after each iteration.
- Continue until all bits have been processed.

Time Complexity: O(32) ≈ O(1)
Space Complexity: O(1)

Note:
An even more efficient approach is Brian Kernighan's Algorithm,
which removes the lowest set bit in each iteration:

    n = n & (n - 1);

Its time complexity is O(k), where k is the number of set bits.

LeetCode:
https://leetcode.com/problems/number-of-1-bits/
-------------------------------------------------------
*/

class Solution {
public:
    int hammingWeight(int n) {

        int count = 0;

        while (n != 0) {

            // Check whether the least significant bit is set
            count += (n & 1);

            // Right shift to process the next bit
            n >>= 1;
        }

        return count;
    }
};