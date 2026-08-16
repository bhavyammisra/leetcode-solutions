#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 15. 3Sum
Difficulty: Medium
Topic: Arrays, Two Pointers, Sorting

Brute Force Approach:
- Generate all possible triplets using three nested loops.
- Check if the sum of each triplet equals zero.
- Use a set to avoid duplicate triplets.

Time Complexity: O(n³)
Space Complexity: O(n) (for storing unique triplets)

Optimal Approach (Sorting + Two Pointers):
- Sort the array.
- Iterate through each element and treat it as the first element of the triplet.
- Use two pointers (left and right) to find the remaining two elements.
- Skip duplicate elements to ensure unique triplets.

Time Complexity: O(n²)
Space Complexity: O(1) (excluding the output list)

LeetCode:
https://leetcode.com/problems/3sum/
-------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array to enable the two-pointer approach
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {

                    // Valid triplet found
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values for the second element
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate values for the third element
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return ans;
    }
};