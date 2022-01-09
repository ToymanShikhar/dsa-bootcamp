#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
   public:
    vector<vector<int>> mat;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        m = matrix.size();
        n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = n - 2; j >= 0; j--) {
                mat[i][j] = mat[i][j] + mat[i][j + 1];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = m - 2; i >= 0; i--) {
                mat[i][j] = mat[i][j] + mat[i + 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int one = mat[row1][col1];
        int two;
        if (col2 + 1 >= n) {
            two = 0;
        } else {
            two = mat[row1][col2 + 1];
        }
        int three;
        if (row2 + 1 >= m) {
            three = 0;
        } else {
            three = mat[row2 + 1][col1];
        }
        int four;
        if (row2 + 1 >= m or col2 + 1 >= n) {
            four = 0;
        } else {
            four = mat[row2 + 1][col2 + 1];
        }

        int ans = one - two - three + four;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
