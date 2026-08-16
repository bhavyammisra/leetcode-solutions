#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 11. Container With Most Water
Difficulty: Medium
Topic: Arrays, Two Pointers

Brute Force Approach:
- Consider every possible pair of lines.
- Calculate the area formed by each pair.
- Keep track of the maximum area encountered.

Time Complexity: O(n²)
Space Complexity: O(1)

Optimal Approach (Two Pointers):
- Initialize two pointers at the beginning and end of the array.
- Calculate the area formed by the two pointers.
- Move the pointer pointing to the shorter line inward, since moving
  the taller line cannot increase the area while the width decreases.
- Continue until both pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/container-with-most-water/
-------------------------------------------------------
*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxWater = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {

            // Calculate the current container width
            int width = right - left;

            // Height is limited by the shorter line
            int currHeight = min(height[left], height[right]);

            // Update the maximum water that can be stored
            maxWater = max(maxWater, width * currHeight);

            // Move the pointer corresponding to the shorter line
            if (height[left] < height[right]) {
                left++;
            }
            else if (height[right] < height[left]) {
                right--;
            }
            else {
                // If both heights are equal, moving either pointer works
                left++;
            }
        }

        return maxWater;
    }
};