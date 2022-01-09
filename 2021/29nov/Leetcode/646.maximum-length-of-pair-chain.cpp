#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
   public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int ans = 0;
        int prev = INT_MIN;

        for (auto p : pairs) {
            if (p[0] > prev) {
                ans++;
                prev = p[1];
            }
        }

        return ans;
    }
};
// @lc code=end
