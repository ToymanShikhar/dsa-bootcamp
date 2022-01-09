#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]].push_back(i);
        }

        int res = 0;

        int last;
        for (int i = 0; i < words.size(); i++) {
            last = -1;
            for (int j = 0; j < words[i].length(); j++) {
                auto it = upper_bound(m[words[i][j]].begin(), m[words[i][j]].end(), last);
                if (it == m[words[i][j]].end()) {
                    break;
                }
                last = *it;
                if (j == words[i].length() - 1) {
                    res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end
