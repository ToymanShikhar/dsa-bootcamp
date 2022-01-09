// Expected Time Complexity: O(sqrt(N))
// Expected Auxiliary Space: O(1)

class Solution {
   public:
    int kThSmallestFactor(int N, int K) {
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                K--;
                if (K == 0) {
                    return i;
                }
            }
        }

        int i = sqrt(N);
        if (i * i == N) {
            i--;
        }
        for (; i >= 1; i--) {
            if (N % i == 0) {
                K--;
                if (K == 0) {
                    return N / i;
                }
            }
        }

        return -1;
    }
};