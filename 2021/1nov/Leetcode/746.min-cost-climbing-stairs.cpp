#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
   public:
    int minCost(vector<int>& cost, int curr, unordered_map<int, int>& m) {
        if (curr == cost.size()) {
            return 0;
        }
        if (curr > cost.size()) {
            return INT_MAX / 2;
        }

        if (m.count(curr)) {
            return m[curr];
        }

        int oneJump = cost[curr] + minCost(cost, curr + 1, m);
        int twoJumps = cost[curr] + minCost(cost, curr + 2, m);

        m[curr] = min(oneJump, twoJumps);

        return m[curr];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> m;
        int zero = minCost(cost, 0, m);

        return min(zero, m[1]);
    }
};
// @lc code=end
