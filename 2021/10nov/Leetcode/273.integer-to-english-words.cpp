#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution {
   public:
    unordered_map<string, string> m;

    string convert(string num) {
        int n = num.length();
        string res;
        if (n == 3) {
            char one = num[0];
            if (one != '0') {
                string search;
                search += one;
                res += m[search];
                res += " Hundred ";
            }
            n--;
            num.erase(0, 1);
        }

        if (n == 2) {
            char one = num[0];
            if (one == '1') {
                res += m[num];
                return res;
            } else if (one != '1' and one != '0') {
                string search;
                search += one;
                search += '-';
                res += m[search];
                res += ' ';
            }

            n--;
            num.erase(0, 1);
        }

        if (n == 1) {
            char one = num[0];
            if (one != '0') {
                res += m[num];
            } else {
                if (res.length() > 0) {
                    res.pop_back();
                }
            }
        }

        return res;
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        m["1"] = "One";
        m["2"] = "Two";
        m["3"] = "Three";
        m["4"] = "Four";
        m["5"] = "Five";
        m["6"] = "Six";
        m["7"] = "Seven";
        m["8"] = "Eight";
        m["9"] = "Nine";
        m["10"] = "Ten";
        m["11"] = "Eleven";
        m["12"] = "Twelve";
        m["13"] = "Thirteen";
        m["14"] = "Fourteen";
        m["15"] = "Fifteen";
        m["16"] = "Sixteen";
        m["17"] = "Seventeen";
        m["18"] = "Eighteen";
        m["19"] = "Nineteen";
        m["2-"] = "Twenty";
        m["3-"] = "Thirty";
        m["4-"] = "Forty";
        m["5-"] = "Fifty";
        m["6-"] = "Sixty";
        m["7-"] = "Seventy";
        m["8-"] = "Eighty";
        m["9-"] = "Ninety";

        string s = to_string(num);
        int n = s.length();

        string res;
        string billion;
        while (n > 9) {
            billion += s[0];
            s.erase(0, 1);
            n--;
        }

        string million;
        while (n > 6) {
            million += s[0];
            s.erase(0, 1);
            n--;
        }

        string thousand;
        while (n > 3) {
            thousand += s[0];
            s.erase(0, 1);
            n--;
        }

        string last = s;

        if (billion != "") {
            string temp = convert(billion);
            if (temp != "") {
                res += temp;
                res += " Billion ";
            }
        }

        if (million != "") {
            string temp = convert(million);
            if (temp != "") {
                res += temp;
                res += " Million ";
            }
        }

        if (thousand != "") {
            string temp = convert(thousand);
            if (temp != "") {
                res += temp;
                res += " Thousand ";
            }
        }

        if (last != "") {
            string temp = convert(last);
            if (temp == "") {
                if (res.length() > 0) {
                    res.pop_back();
                }
            } else {
                res += temp;
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution ss;
    ss.numberToWords(123);

    return 0;
}
