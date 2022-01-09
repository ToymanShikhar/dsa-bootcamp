#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
   public:
    int maxLen(vector<vector<char>>& grid, int i, int j, int m, int n, int dp[301][301]) {
        if (i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0') {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = 1 + maxLen(grid, i, j + 1, m, n, dp);
        int diagonal = 1 + maxLen(grid, i + 1, j + 1, m, n, dp);
        int down = 1 + maxLen(grid, i + 1, j, m, n, dp);

        return dp[i][j] = min(right, min(diagonal, down));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        int dp[301][301];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int l = maxLen(matrix, i, j, m, n, dp);
                ans = max(ans, l * l);
            }
        }

        return ans;
    }
};
// @lc code=end
