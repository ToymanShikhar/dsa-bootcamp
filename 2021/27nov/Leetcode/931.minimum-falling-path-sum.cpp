#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
   public:
    int minCost(vector<vector<int>>& m, int n, int i, int j, int dp[101][101]) {
        if (j < 0 or j >= n) {
            return INT_MAX / 2;
        }
        if (i == n - 1) {
            return m[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int op1 = m[i][j] + minCost(m, n, i + 1, j, dp);
        int op2 = m[i][j] + minCost(m, n, i + 1, j - 1, dp);
        int op3 = m[i][j] + minCost(m, n, i + 1, j + 1, dp);

        return dp[i][j] = min(op1, min(op2, op3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            ans = min(ans, minCost(matrix, matrix.size(), 0, i, dp));
        }
        return ans;
    }
};
// @lc code=end
