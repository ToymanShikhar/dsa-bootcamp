#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120]
 */

// @lc code=start
class Solution {
   public:
    int minPath(vector<vector<int>>& tri, int n, int i, int j, int dp[205][205]) {
        if (i >= n - 1) {
            return tri[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int op1 = tri[i][j] + minPath(tri, n, i + 1, j, dp);
        if (j + 1 < tri[i + 1].size()) {
            int op2 = tri[i][j] + minPath(tri, n, i + 1, j + 1, dp);
            return dp[i][j] = min(op1, op2);
        }
        return dp[i][j] = op1;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[205][205];
        memset(dp, -1, sizeof(dp));
        int n = triangle.size();
        return minPath(triangle, n, 0, 0, dp);
    }
};
// @lc code=end
