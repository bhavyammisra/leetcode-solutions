#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 167. Two Sum II - Input Array Is Sorted
Difficulty: Medium
Topic: Arrays, Two Pointers, Binary Search

Approach (Two Pointers):
- Since the array is sorted, use two pointers:
    - left starts at the beginning.
    - right starts at the end.
- Calculate the sum of the two elements.
- If the sum equals the target, return their 1-based indices.
- If the sum is smaller than the target, move left forward.
- If the sum is greater than the target, move right backward.

Why does this work?
- Moving left forward increases the sum.
- Moving right backward decreases the sum.
- Because the array is sorted, we can eliminate unnecessary
  pairs without checking every combination.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            // Target found
            if (sum == target) {
                return {left + 1, right + 1};
            }

            // Need a larger sum
            else if (sum < target) {
                left++;
            }

            // Need a smaller sum
            else {
                right--;
            }
        }

        return {};
    }
};