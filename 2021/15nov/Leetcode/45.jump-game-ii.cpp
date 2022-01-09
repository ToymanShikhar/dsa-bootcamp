#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
   public:
    int minJumps(int currIndex, vector<int>& nums, int dp[100005]) {
        if (currIndex == nums.size() - 1) {
            return 0;
        }
        if (currIndex >= nums.size()) {
            return 1000000;
        }

        if (dp[currIndex] != -1) {
            return dp[currIndex];
        }

        int ans = INT_MAX / 2;

        for (int i = 1; i <= nums[currIndex]; i++) {
            int op1 = minJumps(currIndex + i, nums, dp);
            ans = min(ans, op1);
        }

        return dp[currIndex] = ans + 1;
    }

    int jump(vector<int>& nums) {
        int dp[10005];
        memset(dp, -1, sizeof(dp));

        return minJumps(0, nums, dp);
    }
};
// @lc code=end

int main() {
    vector<int> n{2, 3, 0, 1, 4};
    Solution ss;
    ss.jump(n);
}
