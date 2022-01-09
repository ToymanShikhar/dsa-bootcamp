#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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
};
// @lc code=end