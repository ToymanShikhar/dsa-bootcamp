#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long currSum = 0;
        int i = 0;
        int j = 0;
        int res = INT_MAX;

        while (j < nums.size()) {
            currSum += nums[j];

            while (currSum >= target) {
                res = min(res, j - i + 1);
                currSum -= nums[i++];
            }

            j++;
        }

        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
