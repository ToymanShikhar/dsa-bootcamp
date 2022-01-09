#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
   public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, pair<int, bool>> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].first++;
            m[nums[i]].second = false;
        }

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]].second == true) {
                continue;
            }
            m[nums[i]].second = true;
            m[nums[i]].first--;
            if (m.count(nums[i] + k) and m[nums[i] + k].first > 0) {
                count++;
            }
            m[nums[i]].first++;
        }

        return count;
    }
};
// @lc code=end