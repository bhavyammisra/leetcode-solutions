#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 347. Top K Frequent Elements
Difficulty: Medium
Topic: Arrays, Hashing, Sorting

Approach (Hash Map + Sorting):
- Count the frequency of each number using an unordered_map.
- Store each (number, frequency) pair in a vector.
- Sort the vector in descending order of frequency.
- Return the first k elements.

Time Complexity: O(n log n)
Space Complexity: O(n)

LeetCode:
https://leetcode.com/problems/top-k-frequent-elements/
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count the frequency of each number
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Store (number, frequency) pairs
        vector<pair<int, int>> freqList;

        for (auto& entry : freq) {
            freqList.push_back({entry.first, entry.second});
        }

        // Sort by frequency in descending order
        sort(freqList.begin(), freqList.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });

        vector<int> result;

        // Take the k most frequent elements
        for (int i = 0; i < k; i++) {
            result.push_back(freqList[i].first);
        }

        return result;
    }
};