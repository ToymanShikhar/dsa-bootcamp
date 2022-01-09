#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int diff = nums[i + 1] - nums[i];
            if (nums[i + 2] - nums[i + 1] != diff) {
                continue;
            }
            for (int j = i + 2; j < n; j++) {
                if (nums[j] - nums[j - 1] != diff) {
                    break;
                }
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end
