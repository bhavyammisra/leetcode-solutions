#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 128. Longest Consecutive Sequence
Difficulty: Medium
Topic: Arrays, Hashing

Approach (Hash Set):
- Insert all numbers into an unordered_set.
- For each number, check if its predecessor (num - 1) exists.
- If it does not exist, the current number is the start of a
  consecutive sequence.
- Keep checking for the next numbers and calculate the sequence length.
- Update the maximum length found.

Example:
    nums = [100, 4, 200, 1, 3, 2]

    Sequence:
    1 -> 2 -> 3 -> 4

    Longest consecutive sequence = 4

Why check num - 1?
- If num - 1 exists, then num is not the start of a sequence.
- This prevents repeatedly traversing the same sequence.

Time Complexity: O(n)
Space Complexity: O(n)

LeetCode:
https://leetcode.com/problems/longest-consecutive-sequence/
-------------------------------------------------------
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Store all numbers in a hash set
        unordered_set<int> seen;
        seen.insert(nums.begin(), nums.end());

        int maxi = 0;

        // Check every unique number
        for (int num : seen) {

            // Only start counting if num is the beginning
            // of a consecutive sequence
            if (!seen.count(num - 1)) {

                int length = 1;
                int current = num;

                // Keep looking for the next consecutive number
                while (seen.count(current + 1)) {
                    length++;
                    current++;
                }

                maxi = max(maxi, length);
            }
        }

        return maxi;
    }
};