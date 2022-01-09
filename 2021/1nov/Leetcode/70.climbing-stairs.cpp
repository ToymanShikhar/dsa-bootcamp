#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
   public:
    int findWays(int currStair, int targetStair, unordered_map<int, int>& m) {
        if (currStair == targetStair) {
            return 1;
        }
        if (currStair > targetStair) {
            return 0;
        }

        if (m.count(currStair)) {
            return m[currStair];
        }

        int oneJump = findWays(currStair + 1, targetStair, m);
        int twoJump = findWays(currStair + 2, targetStair, m);

        return m[currStair] = oneJump + twoJump;
    }

    int climbStairs(int n) {
        unordered_map<int, int> m;
        return findWays(0, n, m);
    }
};
// @lc code=end
