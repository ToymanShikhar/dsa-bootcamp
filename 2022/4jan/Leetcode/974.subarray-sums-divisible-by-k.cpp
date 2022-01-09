#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum = ((sum % k) + k) % k;
            if (m.count(sum)) {
                ans += m[sum];
            }

            m[sum]++;
        }

        return ans;
    }
};
// @lc code=end
