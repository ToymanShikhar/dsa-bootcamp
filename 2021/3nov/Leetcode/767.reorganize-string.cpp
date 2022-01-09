#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
   public:
    string reorganizeString(string s) {
        int n = s.length();

        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto p : m) {
            pq.push({p.second, p.first});
        }

        string res;

        pair<int, int> top = pq.top();
        pq.pop();
        res += top.second;
        top.first--;

        pair<int, int> block = top;

        while (pq.size() > 0) {
            pair<int, int> temp = pq.top();
            pq.pop();
            res += temp.second;
            temp.first--;
            if (block.first > 0) {
                pq.push(block);
            }
            block = temp;
        }
        if (block.first > 0) {
            return "";
        }
        return res;
    }
};
// @lc code=end
