#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
   public:
    int minStartValue(vector<int>& nums) {
        int res = 1;
        int sum = res;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < 1) {
                res += abs(sum - 1);
                sum = 1;
            }
        }

        return res;
    }
};
// @lc code=end
