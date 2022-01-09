#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class compare {
   public:
    bool operator()(vector<int>& v1, vector<int>& v2) {
        if (v1[2] == v2[2]) {
            return v1[1] > v2[1];
        }

        return v1[2] > v2[2];
    }
};

class Solution {
   public:
    static bool compareSort(vector<int>& v1, vector<int>& v2) {
        if (v1[1] == v2[1]) {
            return v1[2] < v2[2];
        }

        return v1[1] < v2[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        sort(trips.begin(), trips.end(), compareSort);

        pq.push(trips[0]);
        int currCap = trips[0][0];
        if (currCap > capacity) {
            return false;
        }

        for (int i = 1; i < trips.size(); i++) {
            while (!pq.empty() and pq.top()[2] <= trips[i][1]) {
                currCap -= pq.top()[0];
                pq.pop();
            }

            currCap += trips[i][0];
            pq.push(trips[i]);
            if (currCap > capacity) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
