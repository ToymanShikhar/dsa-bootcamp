#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
   public:
    int findArea(int i, int j, vector<vector<int>>& grid, bool seen[50][50]) {
        if ((i < 0) or (i >= grid.size()) or (j < 0) or (j >= grid[0].size()) or (seen[i][j]) or (grid[i][j] == 0)) {
            return 0;
        }

        seen[i][j] = true;

        int op1 = findArea(i + 1, j, grid, seen);
        int op2 = findArea(i - 1, j, grid, seen);
        int op3 = findArea(i, j + 1, grid, seen);
        int op4 = findArea(i, j - 1, grid, seen);

        return 1 + op1 + op2 + op3 + op4;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        bool seen[50][50];
        memset(seen, 0, sizeof(seen));

        int area = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int ar = findArea(i, j, grid, seen);
                area = max(area, ar);
            }
        }

        return area;
    }
};
// @lc code=end
int main() {
    Solution ss;
    vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    ss.maxAreaOfIsland(grid);
    return 0;
}
