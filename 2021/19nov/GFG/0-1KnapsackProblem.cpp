// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return maxProfit(wt, val, n, W, 0, dp);
    }

    int maxProfit(int wt[], int val[], int n, int w, int curr, int dp[1001][1001]) {
        if (curr >= n) {
            return 0;
        }

        if (dp[w][curr] != -1) {
            return dp[w][curr];
        }

        int consider = 0;
        if (wt[curr] <= w) {
            consider = val[curr] + maxProfit(wt, val, n, w - wt[curr], curr + 1, dp);
        }

        int notConsider = maxProfit(wt, val, n, w, curr + 1, dp);

        return dp[w][curr] = max(consider, notConsider);
    }
};