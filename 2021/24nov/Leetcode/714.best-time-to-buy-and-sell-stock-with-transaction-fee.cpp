#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
   public:
    int find(vector<int>& prices, int curr, bool canBuy, int dp[50001][2], int fee) {
        if (curr >= prices.size()) {
            return 0;
        }

        if (dp[curr][canBuy] != -1) {
            return dp[curr][canBuy];
        }

        int idle = find(prices, curr + 1, canBuy, dp, fee);

        if (canBuy) {
            int buy = -prices[curr] + find(prices, curr + 1, false, dp, fee);
            return dp[curr][canBuy] = max(idle, buy);
        } else {
            int sell = -fee + prices[curr] + find(prices, curr + 1, true, dp, fee);
            return dp[curr][canBuy] = max(idle, sell);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int dp[50001][2];
        memset(dp, -1, sizeof(dp));
        return find(prices, 0, true, dp, fee);
    }
};
// @lc code=end
