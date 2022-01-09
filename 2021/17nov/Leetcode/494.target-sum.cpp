#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
   public:
    int findWays(vector<int>& nums, int curr, int t, unordered_map<string, int>& m) {
        if (curr == nums.size()) {
            if (t == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        string currKey = to_string(curr) + " " + to_string(t);
        if (m.count(currKey)) {
            return m[currKey];
        }

        int plus = findWays(nums, curr + 1, t - nums[curr], m);
        int minus = findWays(nums, curr + 1, t + nums[curr], m);

        return m[currKey] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> m;
        return findWays(nums, 0, target, m);
    }
};
// @lc code=end
