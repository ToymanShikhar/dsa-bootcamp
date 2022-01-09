#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool one = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                one = true;
            }
            if (nums[i] < 1 or nums[i] > n) {
                nums[i] = 1;
            }
        }

        if (!one) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            int temp = abs(nums[i]) - 1;
            nums[temp] = -1 * abs(nums[temp]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
// @lc code=end