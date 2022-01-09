#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
   public:
    vector<vector<string>> res;

    bool rakhPaaye(int x, int y, vector<string>& b) {
        int n = b.size();
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }
            if (b[i][y] == 'Q') {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == y) {
                continue;
            }
            if (b[x][i] == 'Q') {
                return false;
            }
        }

        int i = x + 1;
        int j = y + 1;
        while (i < n and j < n) {
            if (b[i][j] == 'Q') {
                return false;
            }
            i++;
            j++;
        }

        i = x + 1;
        j = y - 1;
        while (i < n and j >= 0) {
            if (b[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        i = x - 1;
        j = y - 1;
        while (i >= 0 and j >= 0) {
            if (b[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = x - 1;
        j = y + 1;
        while (i >= 0 and j < n) {
            if (b[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void putQueen(int& n, int i, vector<string>& board) {
        if (i == n) {
            res.push_back(board);
            return;
        }

        for (int k = 0; k < n; k++) {
            if (rakhPaaye(i, k, board)) {
                board[i][k] = 'Q';
                putQueen(n, i + 1, board);
                board[i][k] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s;
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        putQueen(n, 0, board);

        return res;
    }
};
// @lc code=end
