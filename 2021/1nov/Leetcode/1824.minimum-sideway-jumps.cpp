#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1824 lang=cpp
 *
 * [1824] Minimum Sideway Jumps
 */

// @lc code=start
class Solution {
   public:
    int jumps(vector<int>& obstacles, int point, int lane, vector<vector<int>>& m) {
        if (point == obstacles.size() - 2) {
            return m[point][lane] = 0;
        }

        if (m[point][lane] != -1) {
            return m[point][lane];
        }

        if (obstacles[point + 1] != lane) {
            return m[point][lane] = jumps(obstacles, point + 1, lane, m);
        }

        if (obstacles[point + 1] == lane) {
            int l1 = 0, l2 = 0;
            if (lane == 1) {
                l1 = 2;
                l2 = 3;
            } else if (lane == 2) {
                l1 = 1;
                l2 = 3;
            } else {
                l1 = 1;
                l2 = 2;
            }
            if (obstacles[point] == l1)
                return m[point][lane] = 1 + jumps(obstacles, point + 1, l2, m);
            else if (obstacles[point] == l2)
                return m[point][lane] = 1 + jumps(obstacles, point + 1, l1, m);
            else
                return m[point][lane] = 1 + min(jumps(obstacles, point + 1, l1, m), jumps(obstacles, point + 1, l2, m));
        }
        return 0;
    }

    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> m(obstacles.size() + 1, vector<int>(4, -1));
        return jumps(obstacles, 0, 2, m);
    }
};
// @lc code=end
