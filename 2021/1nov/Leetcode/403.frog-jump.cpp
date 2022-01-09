#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
   public:
    bool solve(vector<int>& stones, int i, int currStone, int currJump, unordered_map<int, unordered_map<int, int>>& dp) {
        if (currStone == stones[stones.size() - 1]) {
            return true;
        }

        if (dp.count(currStone) and dp[currStone].count(currJump)) {
            return dp[currStone][currJump];
        }

        bool less = false;
        bool equal = false;
        bool more = false;
        int next;
        if (currJump - 1 > 0) {
            int i1 = i;
            next = currStone + (currJump - 1);
            while (i1 < stones.size() and stones[i1] <= next) {
                if (stones[i1] == next) less = solve(stones, i1, currStone + (currJump - 1), currJump - 1, dp);
                i1++;
            }
        }
        int i2 = i;
        next = currStone + (currJump);
        while (i2 < stones.size() and stones[i2] <= next) {
            if (stones[i2] == next) equal = solve(stones, i2, currStone + (currJump), currJump, dp);
            i2++;
        }
        int i3 = i;
        next = currStone + (currJump + 1);
        while (i3 < stones.size() and stones[i3] <= next) {
            if (stones[i3] == next) more = solve(stones, i3, currStone + (currJump + 1), currJump + 1, dp);
            i3++;
        }

        dp[currStone][currJump] = less || equal || more;
        return dp[currStone][currJump];
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        unordered_map<int, unordered_map<int, int>> dp;

        return solve(stones, 1, 1, 1, dp);
    }
};
// @lc code=end
