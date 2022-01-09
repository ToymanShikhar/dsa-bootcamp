#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;

        int currSum = 0;
        int res = 0;

        int find;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            find = currSum - k;
            if (m.count(find)) {
                res += m[find];
            }

            m[currSum]++;
        }

        return res;
    }
};
// @lc code=end
