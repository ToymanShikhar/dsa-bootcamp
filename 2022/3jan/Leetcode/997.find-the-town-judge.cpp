#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n + 1, 0);

        for (int i = 0; i < trust.size(); i++) {
            v[trust[i][0]]--;
            v[trust[i][1]]++;
        }

        for (int i = 1; i < n + 1; i++) {
            if (v[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

// Another approach --->
class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> s;

        for (int i = 0; i < trust.size(); i++) {
            s.insert(trust[i][0]);
        }

        if (s.size() != n - 1) {
            return -1;
        }

        int ans;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) {
                ans = i;
                break;
            }
        }

        for (int i = 0; i < trust.size(); i++) {
            if (trust[i][1] == ans) {
                s.erase(trust[i][0]);
            }
        }

        if (s.empty()) {
            return ans;
        } else {
            return -1;
        }
    }
};
