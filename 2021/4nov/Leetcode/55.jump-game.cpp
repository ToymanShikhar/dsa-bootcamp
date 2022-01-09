#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int jump = 0;

        int i = 0;
        while (i < nums.size() - 1) {
            jump = max(i + nums[i], jump);
            if (i < jump) {
                i++;
            } else {
                break;
            }
        }
        if (i == nums.size() - 1) {
            return true;
        }
        return false;
    }
};
// @lc code=end
