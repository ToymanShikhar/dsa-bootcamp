#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

// @lc code=start
class Solution {
   public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0;

        for (int i = 1; i < nums.size();) {
            if (nums[i] <= nums[i - 1]) {
                if (cnt == 1) {
                    return false;
                }
                cnt++;

                if (i < 2 or nums[i - 2] < nums[i]) {
                    nums.erase(nums.begin() + (i - 1));
                } else {
                    nums.erase(nums.begin() + i);
                }
            } else {
                i++;
            }
        }

        return true;
    }
};
// @lc code=end
