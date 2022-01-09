#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
   public:
    int minCoins(vector<int>& coins, int curr, int amount, int dp[13][10001]) {
        if (amount == 0) {
            return 0;
        }
        if (curr >= coins.size()) {
            return 100000;
        }

        if (dp[curr][amount] != -1) {
            return dp[curr][amount];
        }

        int consider = 100000;
        if (coins[curr] <= amount) {
            consider = 1 + minCoins(coins, curr, amount - coins[curr], dp);
        }

        int notConsider = minCoins(coins, curr + 1, amount, dp);

        return dp[curr][amount] = min(consider, notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        int dp[13][10001];
        memset(dp, -1, sizeof(dp));
        int ans = minCoins(coins, 0, amount, dp);
        if (ans == 100000) {
            return -1;
        }

        return ans;
    }
};
// @lc code=end
