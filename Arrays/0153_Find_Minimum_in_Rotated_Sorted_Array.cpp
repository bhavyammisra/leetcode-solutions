#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 153. Find Minimum in Rotated Sorted Array
Difficulty: Medium
Topic: Arrays, Binary Search

Brute Force Approach:
- Traverse the entire array.
- Keep track of the minimum element encountered.

Time Complexity: O(n)
Space Complexity: O(1)

Optimal Approach (Binary Search):
- Use binary search to identify the sorted half of the array.
- If the left half is sorted, the minimum could be the leftmost element,
  so update the answer and search in the right half.
- Otherwise, the pivot (minimum element) lies in the left half, so update
  the answer with nums[mid] and continue searching left.

Time Complexity: O(log n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
-------------------------------------------------------
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int mini = INT_MAX;

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // The leftmost element is the minimum in this sorted half
                mini = min(mini, nums[low]);

                // Search in the right half
                low = mid + 1;
            }
            else {

                // Pivot lies in the left half
                mini = min(mini, nums[mid]);

                // Search in the left half
                high = mid - 1;
            }
        }

        return mini;
    }
};