#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
   public:
    int maxCost(int arr[], int n, int curr, int dp[10001]) {
        if (curr >= n) {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        int op1 = curr * arr[curr] + maxCost(arr, n, curr + 2, dp);
        int op2 = maxCost(arr, n, curr + 1, dp);

        return dp[curr] = max(op1, op2);
    }

    int deleteAndEarn(vector<int>& nums) {
        int arr[10001];
        memset(arr, 0, sizeof(arr));
        for (auto x : nums) {
            arr[x]++;
        }

        int dp[10001];
        memset(dp, -1, sizeof(dp));

        return maxCost(arr, 10001, 0, dp);
    }
};
// @lc code=end
