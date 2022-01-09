#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution {
   public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            if (costs[i] <= coins) {
                ans++;
                coins -= +costs[i];
            } else {
                break;
            }
        }

        return ans;
    }
};
// @lc code=end
