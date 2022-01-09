#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
   public:
    bool isPossible(vector<int>& arr, int curr) {
        if (curr < 0 or curr >= arr.size() or arr[curr] < 0) {
            return false;
        }
        if (arr[curr] == 0) {
            return true;
        }

        arr[curr] = -arr[curr];  // to mark such that it is not visited again
        bool left = isPossible(arr, curr - arr[curr]);
        bool right = isPossible(arr, curr + arr[curr]);
        arr[curr] = -arr[curr];

        return left or right;
    }

    bool canReach(vector<int>& arr, int start) {
        return isPossible(arr, start);
    }
};
// @lc code=end
