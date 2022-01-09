#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& cuts, int i, int j, unordered_map<int, unordered_map<int, int>>& m) {
        if (j == i + 1) {
            return 0;
        }

        if (m.count(i) and m[i].count(j)) {
            return m[i][j];
        }

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int left = findMin(cuts, i, k, m);
            int right = findMin(cuts, k, j, m);
            int total = (cuts[j] - cuts[i]) + left + right;
            ans = min(ans, total);
        }

        return m[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int num = cuts.size();
        unordered_map<int, unordered_map<int, int>> m;
        return findMin(cuts, 0, num - 1, m);
    }
};
// @lc code=end
