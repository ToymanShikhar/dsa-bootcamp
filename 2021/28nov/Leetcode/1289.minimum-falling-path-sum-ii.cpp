#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
   public:
    int minCost(vector<vector<int>>& grid, int n, int i, int j, int dp[201][201]) {
        if (i == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX / 2;
        for (int k = 0; k < n; k++) {
            if (k == j) {
                continue;
            }
            int tempAns = grid[i][j] + minCost(grid, n, i + 1, k, dp);
            ans = min(ans, tempAns);
        }

        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        int n = grid.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, minCost(grid, n, 0, i, dp));
        }
        return ans;
    }
};
// @lc code=end
