#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution {
   public:
    int maxStones(vector<int>& piles, int curr, int m, vector<int>& sum, unordered_map<int, unordered_map<int, int>>& dp) {
        if (curr >= piles.size()) {
            return 0;
        }

        if (dp.count(curr) and dp[curr].count(m)) {
            return dp[curr][m];
        }

        int ans = INT_MAX / 2;
        for (int i = 0; i < 2 * m; i++) {
            ans = min(ans, maxStones(piles, curr + i + 1, max(m, i + 1), sum, dp));
        }

        return dp[curr][m] = sum[curr] - ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum(n);
        sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sum[i] = sum[i + 1] + piles[i];
        }

        unordered_map<int, unordered_map<int, int>> m;

        return maxStones(piles, 0, 1, sum, m);
    }
};
// @lc code=end
