// Given a NxN matrix of positive integers.
// There are only three possible moves from a cell Matrix[r][c].
//      Matrix [r+1] [c]
//      Matrix [r+1] [c-1]
//      Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

class Solution {
   public:
    int maxCost(vector<vector<int>>& m, int n, int i, int j, int dp[501][501]) {
        if (j < 0 or j >= n) {
            return INT_MIN;
        }
        if (i == n - 1) {
            return m[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int op1 = m[i][j] + maxCost(m, n, i + 1, j, dp);
        int op2 = m[i][j] + maxCost(m, n, i + 1, j - 1, dp);
        int op3 = m[i][j] + maxCost(m, n, i + 1, j + 1, dp);

        return dp[i][j] = max(op1, max(op2, op3));
    }

    int maximumPath(int N, vector<vector<int>> Matrix) {
        int dp[501][501];
        memset(dp, -1, sizeof(dp));
        int ans = INT_MIN;
        for (int i = 0; i < N; i++) {
            ans = max(ans, maxCost(Matrix, N, 0, i, dp));
        }
        return ans;
    }
};