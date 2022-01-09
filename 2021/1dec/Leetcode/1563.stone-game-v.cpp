#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1563 lang=cpp
 *
 * [1563] Stone Game V
 */

// @lc code=start
class Solution {
   public:
    int maxCost(vector<int>& stones, int i, int j, vector<int>& sum, int dp[501][501]) {
        if (i == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MIN;
        for (int cut = i; cut < j; cut++) {
            int left = sum[cut] - sum[i] + stones[i];
            int right = sum[j] - sum[cut];

            int tempAns;
            if (left < right) {
                tempAns = left + maxCost(stones, i, cut, sum, dp);
            } else if (left > right) {
                tempAns = right + maxCost(stones, cut + 1, j, sum, dp);
            } else {
                int op1 = left + maxCost(stones, i, cut, sum, dp);
                int op2 = right + maxCost(stones, cut + 1, j, sum, dp);
                tempAns = max(op1, op2);
            }

            ans = max(ans, tempAns);
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sum(n);
        sum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + stoneValue[i];
        }

        int dp[501][501];
        memset(dp, -1, sizeof(dp));

        return maxCost(stoneValue, 0, stoneValue.size() - 1, sum, dp);
    }
};
// @lc code=end
