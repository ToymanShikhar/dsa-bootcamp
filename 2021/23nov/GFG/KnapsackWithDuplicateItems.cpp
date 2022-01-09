class Solution {
   public:
    int maxProfit(int wt[], int val[], int n, int w, int curr, int dp[1001][1001]) {
        if (curr >= n) {
            return 0;
        }

        if (dp[w][curr] != -1) {
            return dp[w][curr];
        }

        int consider = 0;
        if (wt[curr] <= w) {
            consider = val[curr] + maxProfit(wt, val, n, w - wt[curr], curr, dp);
        }

        int notConsider = maxProfit(wt, val, n, w, curr + 1, dp);

        return dp[w][curr] = max(consider, notConsider);
    }

    int knapSack(int N, int W, int val[], int wt[]) {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return maxProfit(wt, val, N, W, 0, dp);
    }
};