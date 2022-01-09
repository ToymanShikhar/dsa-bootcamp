#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
   public:
    int minHP(vector<vector<int>>& dungeon, int i, int j, int m, int n, int dp[201][201]) {
        if (i == m - 1 and j == n - 1) {
            if (1 - dungeon[i][j] < 1) {
                return 1;
            } else {
                return 1 - dungeon[i][j];
            }
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX / 2;
        if (j + 1 < n) {
            int tempAns1 = minHP(dungeon, i, j + 1, m, n, dp);
            ans = min(ans, tempAns1);
        }
        if (i + 1 < m) {
            int tempAns2 = minHP(dungeon, i + 1, j, m, n, dp);
            ans = min(ans, tempAns2);
        }

        int temp = ans - dungeon[i][j];
        if (temp < 1) {
            return dp[i][j] = 1;
        } else {
            return dp[i][j] = temp;
        }
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        int dp[201][201];
        memset(dp, -1, sizeof(dp));

        return minHP(dungeon, 0, 0, m, n, dp);
    }
};
// @lc code=end
