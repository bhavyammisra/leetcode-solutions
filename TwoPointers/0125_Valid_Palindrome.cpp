#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 125. Valid Palindrome
Difficulty: Easy
Topic: Strings, Two Pointers

Approach (Two Pointers):
- Use two pointers, one starting from the left and one from the right.
- Skip any characters that are not alphanumeric.
- Compare the characters after converting them to lowercase.
- If they differ, the string is not a palindrome.
- Move both pointers inward and continue until they meet.

Example:
    "A man, a plan, a canal: Panama"

    Ignoring spaces and punctuation:
    "amanaplanacanalpanama"

    This reads the same forwards and backwards.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/valid-palindrome/
-------------------------------------------------------
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move both pointers inward
            left++;
            right--;
        }

        return true;
    }
};