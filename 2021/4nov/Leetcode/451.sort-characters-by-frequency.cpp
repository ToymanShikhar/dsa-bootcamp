#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto p : m) {
            pq.push({p.second, p.first});
        }

        string res;

        while (pq.size() > 0) {
            auto top = pq.top();
            pq.pop();

            for (int i = 0; i < top.first; i++) {
                res += top.second;
            }
        }

        return res;
    }
};
// @lc code=end
