#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
   public:
    int solve(vector<vector<int>>& grid, int row, int c1, int c2, int dp[70][70][70]) {
        if (row >= grid.size()) {
            return 0;
        }

        if (dp[row][c1][c2] != -1) {
            return dp[row][c1][c2];
        }

        int ans = 0;
        int cols = grid[row].size();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nextC1 = c1 + i;
                int nextC2 = c2 + j;
                if (nextC1 >= 0 and nextC1 < cols and nextC2 >= 0 and nextC2 < cols) {
                    ans = max(ans, solve(grid, row + 1, nextC1, nextC2, dp));
                }
            }
        }

        int cherry = c1 == c2 ? grid[row][c1] : (grid[row][c1] + grid[row][c2]);
        return dp[row][c1][c2] = ans + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[70][70][70];
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, grid[0].size() - 1, dp);
    }
};
// @lc code=end
