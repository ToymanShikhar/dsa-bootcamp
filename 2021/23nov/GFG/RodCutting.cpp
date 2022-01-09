class Solution {
   public:
    int maxPrice(int price[], int N, int curr, int l, int dp[1001][1001]) {
        if (l == 0) {
            return 0;
        }
        if (curr >= N) {
            return 0;
        }

        if (dp[curr][l] != -1) {
            return dp[curr][l];
        }

        int consider = 0;
        if ((curr + 1) <= l) {
            consider = price[curr] + maxPrice(price, N, curr, l - (curr + 1), dp);
        }
        int notConsider = maxPrice(price, N, curr + 1, l, dp);

        return dp[curr][l] = max(consider, notConsider);
    }
    int cutRod(int price[], int n) {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return maxPrice(price, n, 0, n, dp);
    }
};