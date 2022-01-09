#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
   public:
    int ways(vector<vector<int>>& og, int i, int j, int m, int n, int dp[101][101]) {
        if (i == m - 1 and j == n - 1) {
            return 1;
        }
        if (i >= m or j >= n) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (og[i][j] == 1) {
            return dp[i][j] = 0;
        }

        int right = ways(og, i, j + 1, m, n, dp);
        int down = ways(og, i + 1, j, m, n, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 or obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return ways(obstacleGrid, 0, 0, m, n, dp);
    }
};
// @lc code=end
