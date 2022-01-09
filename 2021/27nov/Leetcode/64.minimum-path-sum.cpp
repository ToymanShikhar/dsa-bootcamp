#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
   public:
    int ways(vector<vector<int>>& og, int i, int j, int m, int n, int dp[201][201]) {
        if (i == m - 1 and j == n - 1) {
            return og[m - 1][n - 1];
        }
        if (i >= m or j >= n) {
            return INT_MAX / 2;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = og[i][j] + ways(og, i, j + 1, m, n, dp);
        int down = og[i][j] + ways(og, i + 1, j, m, n, dp);

        return dp[i][j] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        return ways(grid, 0, 0, m, n, dp);
    }
};
// @lc code=end
