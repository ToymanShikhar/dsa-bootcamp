#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
   public:
    int find(vector<int>& prices, int curr, bool canBuy, int dp[100001][2]) {
        if (curr >= prices.size()) {
            return 0;
        }

        if (dp[curr][canBuy] != -1) {
            return dp[curr][canBuy];
        }

        int idle = find(prices, curr + 1, canBuy, dp);

        if (canBuy) {
            int buy = -prices[curr] + find(prices, curr + 1, false, dp);
            return dp[curr][canBuy] = max(idle, buy);
        } else {
            int sell = prices[curr] + find(prices, curr + 1, true, dp);
            return dp[curr][canBuy] = max(idle, sell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int dp[100001][2];
        memset(dp, -1, sizeof(dp));
        return find(prices, 0, true, dp);
    }
};
// @lc code=end
