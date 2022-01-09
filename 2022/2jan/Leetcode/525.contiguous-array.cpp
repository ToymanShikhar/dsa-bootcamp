#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        int currSum = 0;
        m[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                currSum += -1;
            } else {
                currSum += 1;
            }

            if (m.count(currSum)) {
                res = max(res, i - m[currSum]);
            } else {
                m[currSum] = i;
            }
        }

        return res;
    }
};
// @lc code=end
