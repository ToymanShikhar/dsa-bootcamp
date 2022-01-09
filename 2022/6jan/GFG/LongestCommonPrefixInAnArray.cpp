class Solution {
   public:
    string check(string& s1, string& s2) {
        string res;
        int i = 0;
        int j = 0;
        while (i < s1.length() and j < s2.length()) {
            if (s1[i] == s2[j]) {
                res += s1[i];
                i++;
                j++;
            } else {
                break;
            }
        }

        return res;
    }

    string longestCommonPrefix(string arr[], int N) {
        string res = arr[0];
        for (int i = 1; i < N; i++) {
            res = check(res, arr[i]);
        }

        if (res.size() == 0) {
            return "-1";
        }

        return res;
    }
};