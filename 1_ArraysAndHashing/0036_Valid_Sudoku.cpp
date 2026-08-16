#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 36. Valid Sudoku
Difficulty: Medium
Topic: Arrays, Hashing

Approach:
- Check every row for duplicate digits.
- Check every column for duplicate digits.
- Check each of the nine 3x3 boxes for duplicate digits.
- Use an unordered_set to keep track of digits already seen.
- Ignore empty cells represented by '.'.

Time Complexity: O(9²) ≈ O(1)
Space Complexity: O(9) ≈ O(1)

LeetCode:
https://leetcode.com/problems/valid-sudoku/
-------------------------------------------------------
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check all rows
        for (int row = 0; row < 9; row++) {

            unordered_set<char> seen;

            for (int col = 0; col < 9; col++) {

                char cell = board[row][col];

                // Ignore empty cells
                if (cell == '.') continue;

                // Duplicate found
                if (seen.count(cell)) return false;

                seen.insert(cell);
            }
        }

        // Check all columns
        for (int col = 0; col < 9; col++) {

            unordered_set<char> seen;

            for (int row = 0; row < 9; row++) {

                char cell = board[row][col];

                // Ignore empty cells
                if (cell == '.') continue;

                // Duplicate found
                if (seen.count(cell)) return false;

                seen.insert(cell);
            }
        }

        // Check all 3x3 boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {

            for (int boxCol = 0; boxCol < 3; boxCol++) {

                unordered_set<char> seen;

                // Traverse the current 3x3 box
                for (int i = 0; i < 3; i++) {

                    for (int j = 0; j < 3; j++) {

                        int row = boxRow * 3 + i;
                        int col = boxCol * 3 + j;

                        char cell = board[row][col];

                        // Ignore empty cells
                        if (cell == '.') continue;

                        // Duplicate found
                        if (seen.count(cell)) return false;

                        seen.insert(cell);
                    }
                }
            }
        }

        return true;
    }
};