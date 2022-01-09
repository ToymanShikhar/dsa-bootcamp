#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
   public:
    int maxStones(vector<int>& piles, int curr, vector<int>& sum, unordered_map<int, int>& dp) {
        if (curr >= piles.size()) {
            return 0;
        }

        if (dp.count(curr)) {
            return dp[curr];
        }

        int ans = INT_MAX / 2;
        for (int i = 0; i < 3; i++) {
            ans = min(ans, maxStones(piles, curr + i + 1, sum, dp));
        }

        return dp[curr] = sum[curr] - ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sum(n);
        sum[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sum[i] = sum[i + 1] + stoneValue[i];
        }

        unordered_map<int, int> m;

        double alice = (double)maxStones(stoneValue, 0, sum, m);

        double cmp = sum[0] / 2.0;

        if (alice > cmp) {
            return "Alice";
        } else if (alice == cmp) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};
// @lc code=end
