#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
   public:
    char ans[9][9];
    bool rakhPaaye(int i, int j, int n, vector<vector<char>>& b) {
        for (int x = 0; x < 9; x++) {
            if ((b[i][x] - '0') == n) {
                return false;
            }
        }

        for (int x = 0; x < 9; x++) {
            if ((b[x][j] - '0') == n) {
                return false;
            }
        }

        for (int x = i / 3 * 3; x < (i / 3 * 3 + 3); x++) {
            for (int y = j / 3 * 3; y < (j / 3 * 3 + 3); y++) {
                if ((b[x][y] - '0') == n) {
                    return false;
                }
            }
        }

        return true;
    }
    void solve(int i, int j, vector<vector<char>>& b) {
        if (i == 9) {
            for (int p = 0; p < 9; p++) {
                for (int q = 0; q < 9; q++) {
                    ans[p][q] = b[p][q];
                }
            }
            return;
        }
        if (j == 9) {
            solve(i + 1, 0, b);
            return;
        }

        if (b[i][j] == '.') {
            for (int k = 1; k <= 9; k++) {
                if (rakhPaaye(i, j, k, b)) {
                    b[i][j] = '0' + k;
                    solve(i, j + 1, b);
                    b[i][j] = '.';
                }
            }
        } else {
            solve(i, j + 1, b);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
        for (int p = 0; p < 9; p++) {
            for (int q = 0; q < 9; q++) {
                board[p][q] = ans[p][q];
            }
        }
    }
};
// @lc code=end
