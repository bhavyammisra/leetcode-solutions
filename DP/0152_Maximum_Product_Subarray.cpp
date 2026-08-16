#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 152. Maximum Product Subarray
Difficulty: Medium
Topic: Arrays, Dynamic Programming

Brute Force Approach:
- Generate all possible subarrays.
- Calculate the product of each subarray.
- Keep track of the maximum product encountered.

Time Complexity: O(n²)
Space Complexity: O(1)

Optimal Approach (Prefix & Suffix Traversal):
- Traverse the array from both the left (prefix) and the right (suffix)
  simultaneously.
- Reset the running product to 1 whenever it becomes 0.
- At each step, update the maximum product using both the prefix and suffix
  products.
- This handles cases where the maximum product subarray is affected by
  negative numbers or zeros.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/maximum-product-subarray/
-------------------------------------------------------
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prefix = 1;
        int suffix = 1;
        int maxProd = nums[0];

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Reset the running product if it becomes zero
            if (prefix == 0)
                prefix = 1;

            if (suffix == 0)
                suffix = 1;

            // Compute prefix and suffix products
            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            // Update the maximum product found so far
            maxProd = max(maxProd, max(prefix, suffix));
        }

        return maxProd;
    }
};