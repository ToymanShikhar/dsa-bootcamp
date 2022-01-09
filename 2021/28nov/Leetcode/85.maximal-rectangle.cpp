#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = -1;
            } else {
                int top = st.top();
                left[i] = top;
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n;
            } else {
                int top = st.top();
                right[i] = top;
            }

            st.push(i);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            left[i] = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, left[i]);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        if (cols == 0) {
            return 0;
        }

        int ans = INT_MIN;

        vector<int> arr(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') {
                    arr[j] = 0;
                } else {
                    arr[j]++;
                }
            }

            int tempAns = largestRectangleArea(arr);
            ans = max(ans, tempAns);
        }

        return ans;
    }
};
// @lc code=end
