#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: 121. Best Time to Buy and Sell Stock
Difficulty: Easy
Topic: Arrays, Greedy

Brute Force Approach:
- For every day, consider it as the buying day.
- Check every future day as the selling day.
- Calculate the profit for each pair and keep track of the maximum profit.

Time Complexity: O(n²)
Space Complexity: O(1)

Optimal Approach:
- Traverse the array once while maintaining the minimum stock price
  encountered so far.
- For each day's price, calculate the profit if the stock were sold on
  that day.
- Update the maximum profit whenever a larger profit is found.

Time Complexity: O(n)
Space Complexity: O(1)

LeetCode:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
-------------------------------------------------------
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum buying price
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                // Calculate profit if sold today
                int profit = prices[i] - minPrice;

                // Update the maximum profit
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};