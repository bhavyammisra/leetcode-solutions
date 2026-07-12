#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 238. Product of Array Except Self
Difficulty: Medium
Topic: Arrays, Prefix Sum

Brute Force Approach:
- For each element, traverse the entire array and multiply
  every other element except itself.
- Store the resulting product in the answer array.

Time Complexity: O(n²)
Space Complexity: O(1) (excluding the output array)

Better Approach (Prefix & Suffix Arrays):
- Create a prefix array where prefix[i] stores the product
  of all elements before index i.
- Create a suffix array where suffix[i] stores the product
  of all elements after index i.
- The answer for each index is:
      prefix[i] * suffix[i]

Time Complexity: O(n)
Space Complexity: O(n)

Optimal Approach:
- Store prefix products directly in the answer array.
- Traverse from right to left while maintaining a running
  suffix product.
- Multiply the current answer by the suffix product.

Time Complexity: O(n)
Space Complexity: O(1) (excluding the output array)

LeetCode:
https://leetcode.com/problems/product-of-array-except-self/
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> answer(n);

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // Compute suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        // Compute final answer
        for (int i = 0; i < n; i++) {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};