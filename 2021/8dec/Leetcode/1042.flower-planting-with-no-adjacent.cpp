#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
class Solution {
   public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> edges(n);
        for (auto p : paths) {
            edges[p[0] - 1].push_back(p[1] - 1);
            edges[p[1] - 1].push_back(p[0] - 1);
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> edge = edges[i];
            for (int j = 1; j <= 4; j++) {
                int isPresent = false;
                for (int k = 0; k < edge.size(); k++) {
                    if (res[edge[k]] == j) {
                        isPresent = true;
                        break;
                    }
                }
                if (!isPresent) {
                    res[i] = j;
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end
