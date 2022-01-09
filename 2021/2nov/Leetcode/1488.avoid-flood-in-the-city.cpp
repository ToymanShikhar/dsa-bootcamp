#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1488 lang=cpp
 *
 * [1488] Avoid Flood in The City
 */

// @lc code=start
class Solution {
   public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n);
        set<int> s;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                s.insert(i);
                res[i] = 1;
            } else {
                if (m.count(rains[i]) == 0) {
                    m[rains[i]] = i;
                    res[i] = -1;
                } else {
                    int idx = m[rains[i]];
                    auto it = s.lower_bound(idx);
                    if (it != s.end()) {
                        res[*it] = rains[i];
                        m[rains[i]] = i;
                        s.erase(it);
                    } else {
                        res.resize(0);
                        return res;
                    }
                    res[i] = -1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
