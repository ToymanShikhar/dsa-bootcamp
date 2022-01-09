#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
   public:
    bool findIsland(int i, int j, vector<vector<char>>& grid, bool seen[300][300]) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or seen[i][j] or (grid[i][j] - '0' == 0)) {
            return 0;
        }

        seen[i][j] = true;

        findIsland(i + 1, j, grid, seen);
        findIsland(i, j + 1, grid, seen);
        findIsland(i - 1, j, grid, seen);
        findIsland(i, j - 1, grid, seen);

        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        bool seen[300][300];
        memset(seen, 0, sizeof(seen));

        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                bool isDiff = findIsland(i, j, grid, seen);
                count += isDiff;
            }
        }

        return count;
    }
};
// @lc code=end