#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
class Solution {
   public:
    bool isPossible(int maxChoice, int total, vector<bool>& st, unordered_map<int, bool>& dp) {
        if (total <= 0) {
            return false;
        }

        int currKey = 0;
        for (int i = 0; i < 21; i++) {
            if (st[i]) {
                int mask = 1 << i;
                currKey = currKey | mask;
            }
        }

        if (dp.count(currKey)) {
            return dp[currKey];
        }

        for (int i = 1; i <= maxChoice; i++) {
            if (st[i]) {
                continue;
            }

            st[i] = true;
            bool tempAns = isPossible(maxChoice, total - i, st, dp);
            st[i] = false;
            if (tempAns == false) {
                dp[currKey] = true;
                return true;
            }
        }

        dp[currKey] = false;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 1) {
            return true;
        }
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
            return false;
        }

        unordered_map<int, bool> dp;

        vector<bool> st(21, false);

        return isPossible(maxChoosableInteger, desiredTotal, st, dp);
    }
};
// @lc code=end
