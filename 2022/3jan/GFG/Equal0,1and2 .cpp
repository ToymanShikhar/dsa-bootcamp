class Solution {
   public:
    long long getSubstringWithEqual012(string str) {
        unordered_map<string, long long> m;
        long long co = 0, cz = 0, ct = 0;
        string key = to_string(cz - co) + "#" + to_string(ct - co);
        m[key] = 1;

        long long ans = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') {
                cz++;
            }
            if (str[i] == '1') {
                co++;
            }
            if (str[i] == '2') {
                ct++;
            }

            string currKey = to_string(cz - co) + "#" + to_string(ct - co);
            if (m.count(currKey)) {
                ans += m[currKey];
            }
            m[currKey]++;
        }

        return ans;
    }
};