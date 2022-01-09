class Solution {
   public:
    vector<int> search(string txt, string pat) {
        vector<int> res;

        int i = 0;
        int j = 0;

        while (i < pat.length()) {
            if (pat[i] == txt[j]) {
                int idx = i;

                while (j < txt.length() and pat[i] == txt[j]) {
                    i++;
                    j++;
                }

                if (j == txt.length()) {
                    res.push_back(idx + 1);
                }

                j = 0;
                i = idx + 1;
            } else {
                j = 0;
                i++;
            }
        }

        return res;
    }
};