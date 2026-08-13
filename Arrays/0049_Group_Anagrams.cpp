#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 49. Group Anagrams
Difficulty: Medium
Topic: Arrays, Strings, Hashing, Sorting

Brute Force Approach:
- Compare every pair of strings.
- Check whether they are anagrams.
- Group strings that belong together.

Time Complexity: O(n² * k log k)
Space Complexity: O(n)

Optimal Approach (Sorting + Hash Map):
- Create a "fingerprint" for each word by sorting its characters.
- Anagrams produce the same sorted string.
- Use the sorted string as the key in an unordered_map.
- Store all words with the same fingerprint in the same group.

Example:
    "eat" → "aet"
    "tea" → "aet"
    "ate" → "aet"

Therefore, all three words are placed in the same group.

Time Complexity: O(n * k log k)
Space Complexity: O(n * k)

Where:
- n = number of strings
- k = maximum length of a string

LeetCode:
https://leetcode.com/problems/group-anagrams/
-------------------------------------------------------
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Map each sorted fingerprint to its group of anagrams
        unordered_map<string, vector<string>> groups;

        for (string& word : strs) {

            // Create a fingerprint by sorting the characters
            string fingerprint = word;
            sort(fingerprint.begin(), fingerprint.end());

            // Add the original word to its corresponding group
            groups[fingerprint].push_back(word);
        }

        vector<vector<string>> result;

        // Collect all groups into the result
        for (auto& entry : groups) {
            result.push_back(entry.second);
        }
        // fingerprint -> group of anagrams

        return result;
    }
};