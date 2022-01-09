#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        ans[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] * nums[i + 1];
        }

        int left = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = left * ans[i];
            left *= nums[i];
        }

        return ans;
    }
};
// @lc code=end
