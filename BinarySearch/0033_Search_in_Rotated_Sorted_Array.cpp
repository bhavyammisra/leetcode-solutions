#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 33. Search in Rotated Sorted Array
Difficulty: Medium
Topic: Arrays, Binary Search

Brute Force Approach:
- Traverse the entire array.
- Compare each element with the target.
- Return the index if found; otherwise return -1.

Time Complexity: O(n)
Space Complexity: O(1)

Optimal Approach (Binary Search):
- At each step, determine which half of the array is sorted.
- Check if the target lies within the sorted half.
- If it does, continue searching in that half.
- Otherwise, search in the other half.
- Repeat until the target is found or the search space becomes empty.

Time Complexity: O(log n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/search-in-rotated-sorted-array/
-------------------------------------------------------
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Target lies in the left sorted half
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in the right sorted half
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};