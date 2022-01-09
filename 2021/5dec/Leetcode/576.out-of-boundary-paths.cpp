#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
   public:
    int findWays(int m, int n, int moves, int i, int j, int dp[51][51][51]) {
        if (i < 0 or i >= m or j < 0 or j >= n) {
            return 1;
        }

        if (dp[i][j][moves] != -1) {
            return dp[i][j][moves];
        }

        int left = 0, right = 0, top = 0, down = 0;
        if (moves > 0) {
            left = findWays(m, n, moves - 1, i, j - 1, dp) % 1000000007;
            right = findWays(m, n, moves - 1, i, j + 1, dp) % 1000000007;
            top = findWays(m, n, moves - 1, i - 1, j, dp) % 1000000007;
            down = findWays(m, n, moves - 1, i + 1, j, dp) % 1000000007;
        }

        return dp[i][j][moves] = ((((left % 1000000007 + right % 1000000007) % 1000000007 + top % 1000000007) % 1000000007) + down % 1000000007) % 1000000007;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[51][51][51];
        memset(dp, -1, sizeof(dp));
        return findWays(m, n, maxMove, startRow, startColumn, dp) % 1000000007;
    }
};
// @lc code=end
