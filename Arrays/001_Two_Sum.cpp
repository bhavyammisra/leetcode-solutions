#include<bits/stdc++.h>
using namespace std;

/*
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Topic: Arrays, Hash Map
 *
 * LeetCode:
 * https://leetcode.com/problems/two-sum/
 *
 * Brute Force Approach:
 * - Check every possible pair of elements.
 * - Time Complexity: O(n²)
 * - Space Complexity: O(1)
 *
 * Optimal Approach:
 * - Store previously seen numbers in a hash map.
 * - For each number, check if its complement exists.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};