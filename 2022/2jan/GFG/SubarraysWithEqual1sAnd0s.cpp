class Solution {
   public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int nums[], int n) {
        unordered_map<int, int> m;
        int res = 0;
        int currSum = 0;
        m[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                currSum += -1;
            } else {
                currSum += 1;
            }

            if (m.count(currSum)) {
                res += m[currSum];
                m[currSum]++;
            } else {
                m[currSum]++;
            }
        }

        return res;
    }
};