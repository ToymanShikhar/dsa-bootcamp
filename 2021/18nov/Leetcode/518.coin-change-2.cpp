#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
   public:
    int ways(vector<int>& coins, int curr, int amount, int dp[301][5001]) {
        if (amount == 0) {
            return 1;
        }
        if (curr >= coins.size()) {
            return 0;
        }

        if (dp[curr][amount] != -1) {
            return dp[curr][amount];
        }

        int consider = 0;
        if (coins[curr] <= amount) {
            consider = ways(coins, curr, amount - coins[curr], dp);
        }

        int notConsider = ways(coins, curr + 1, amount, dp);

        return dp[curr][amount] = consider + notConsider;
    }
    int change(int amount, vector<int>& coins) {
        int dp[301][5001];
        memset(dp, -1, sizeof(dp));

        return ways(coins, 0, amount, dp);
    }
};
// @lc code=end
