#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
   public:
    int countLive(int i, int j, vector<vector<int>>& b) {
        int cnt = 0;
        int rows = b.size();
        int cols = b[0].size();

        if (j + 1 < cols and (b[i][j + 1] % 2) == 1) {
            cnt++;
        }
        if (j + 1 < cols and i + 1 < rows and (b[i + 1][j + 1] % 2) == 1) {
            cnt++;
        }
        if (i + 1 < rows and (b[i + 1][j] % 2) == 1) {
            cnt++;
        }
        if (i + 1 < rows and j - 1 >= 0 and (b[i + 1][j - 1] % 2) == 1) {
            cnt++;
        }
        if (j - 1 >= 0 and (b[i][j - 1] % 2) == 1) {
            cnt++;
        }
        if (j - 1 >= 0 and i - 1 >= 0 and (b[i - 1][j - 1] % 2) == 1) {
            cnt++;
        }
        if (i - 1 >= 0 and (b[i - 1][j] % 2) == 1) {
            cnt++;
        }
        if (i - 1 >= 0 and j + 1 < cols and (b[i - 1][j + 1] % 2) == 1) {
            cnt++;
        }

        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int live = countLive(i, j, board);

                if (board[i][j] == 1) {
                    if (live < 2 or live > 3) {
                        board[i][j] = (board[i][j] % 2) + (2 * (0 % 2));
                    } else {
                        board[i][j] = (board[i][j] % 2) + (2 * (1 % 2));
                    }
                } else {
                    if (live == 3) {
                        board[i][j] = (board[i][j] % 2) + (2 * (1 % 2));
                    } else {
                        board[i][j] = (board[i][j] % 2) + (2 * (0 % 2));
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = board[i][j] / 2;
            }
        }
    }
};
// @lc code=end
