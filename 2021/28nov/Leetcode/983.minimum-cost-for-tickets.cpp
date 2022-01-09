#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
   public:
    int minCost(vector<int>& days, vector<int>& costs, int curr, int range, int dp[366][410]) {
        if (curr >= days.size()) {
            return 0;
        }

        if (dp[curr][range] != -1) {
            return dp[curr][range];
        }

        if (days[curr] <= range) {
            return dp[curr][range] = minCost(days, costs, curr + 1, range, dp);
        } else {
            int op1 = costs[0] + minCost(days, costs, curr + 1, 0, dp);
            int op2 = costs[1] + minCost(days, costs, curr + 1, days[curr] + 6, dp);
            int op3 = costs[2] + minCost(days, costs, curr + 1, days[curr] + 29, dp);

            return dp[curr][range] = min(op1, min(op2, op3));
        }
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366][410];
        memset(dp, -1, sizeof(dp));
        return minCost(days, costs, 0, 0, dp);
    }
};
// @lc code=end
