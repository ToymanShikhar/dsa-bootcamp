#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        vector<int> ans;
        pair<int, int> res(1, 0);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] > res.first) {
                res.first = dp[i];
                res.second = i;
            }
        }

        int i = res.second;
        while (i != -1) {
            ans.push_back(nums[i]);
            i = pre[i];
        }

        return ans;
    }
};
// @lc code=end
