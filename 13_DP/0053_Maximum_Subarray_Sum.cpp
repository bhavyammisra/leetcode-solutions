#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 53. Maximum Subarray
Difficulty: Medium
Topic: Arrays, Dynamic Programming (Kadane's Algorithm)

Brute Force Approach:
- Generate all possible subarrays.
- Calculate the sum of each subarray.
- Keep track of the maximum sum encountered.

Time Complexity: O(n²)
Space Complexity: O(1)

Better Approach:
- Use prefix sums to calculate subarray sums more efficiently.
- Iterate over all possible starting and ending indices while
  using the prefix sum array to compute subarray sums.

Time Complexity: O(n²)
Space Complexity: O(n)

Optimal Approach (Kadane's Algorithm):
- Traverse the array while maintaining the sum of the current subarray.
- Update the maximum sum whenever the current sum becomes larger.
- If the current sum becomes negative, reset it to 0 since a negative
  prefix would only reduce the sum of future subarrays.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/maximum-subarray/
-------------------------------------------------------
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = nums[0];
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Add the current element to the running sum
            currentSum += nums[i];

            // Update the maximum subarray sum found so far
            maxSum = max(maxSum, currentSum);

            // If the running sum becomes negative,
            // start a new subarray from the next element
            if (currentSum < 0)
                currentSum = 0;
        }

        return maxSum;
    }
};