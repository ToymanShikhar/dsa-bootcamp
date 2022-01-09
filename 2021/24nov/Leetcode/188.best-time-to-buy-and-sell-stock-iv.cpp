#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
   public:
    int find(vector<int>& prices, int curr, bool canBuy, int tranCount, int dp[100001][2][101]) {
        if (curr >= prices.size() or tranCount <= 0) {
            return 0;
        }

        if (dp[curr][canBuy][tranCount] != -1) {
            return dp[curr][canBuy][tranCount];
        }

        int idle = find(prices, curr + 1, canBuy, tranCount, dp);

        if (canBuy) {
            int buy = -prices[curr] + find(prices, curr + 1, false, tranCount, dp);
            return dp[curr][canBuy][tranCount] = max(idle, buy);
        } else {
            int sell = prices[curr] + find(prices, curr + 1, true, tranCount - 1, dp);
            return dp[curr][canBuy][tranCount] = max(idle, sell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int dp[100001][2][101];
        memset(dp, -1, sizeof(dp));
        return find(prices, 0, true, k, dp);
    }
};
// @lc code=end
