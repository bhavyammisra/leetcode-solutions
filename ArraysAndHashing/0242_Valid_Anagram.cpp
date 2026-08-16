#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 242. Valid Anagram
Difficulty: Easy
Topic: Hashing, Strings

Brute Force Approach:
- Sort both strings.
- If the sorted strings are equal, they are anagrams.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding the sorting implementation)

Optimal Approach (Hash Map):
- Count the frequency of every character in both strings.
- Compare the two frequency maps.
- If the maps are equal, both strings contain the same characters
  with the same frequencies.

Time Complexity: O(n)
Space Complexity: O(k)
where k is the number of distinct characters.

LeetCode:
https://leetcode.com/problems/valid-anagram/
-------------------------------------------------------
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> s1;
        unordered_map<char, int> s2;

        // Count the frequency of characters in s
        for (char c : s) {
            s1[c]++;
        }

        // Count the frequency of characters in t
        for (char c : t) {
            s2[c]++;
        }

        // Compare the frequency maps
        return s1 == s2;
    }
};