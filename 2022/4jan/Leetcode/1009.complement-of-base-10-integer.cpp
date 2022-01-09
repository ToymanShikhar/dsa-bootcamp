/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
   public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 0;
        int flag = 1;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            int bit = mask & n;
            if (bit == 0 and flag == 1) {
                continue;
            }
            flag = 0;
            bit = !bit;

            res = res | (bit << i);
        }

        return res;
    }
};
// @lc code=end
