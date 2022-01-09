#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
class StreamChecker {
   public:
    class Node {
       public:
        bool isEnd;
        Node** childs;
        Node() {
            isEnd = false;
            childs = new Node*[26];
            for (int i = 0; i < 26; i++) {
                childs[i] = NULL;
            }
        }
    };

    Node* root;
    string stream;

    StreamChecker(vector<string>& words) {
        root = new Node;
        for (auto s : words) {
            Node* curr = root;
            for (int i = s.length() - 1; i >= 0; i--) {
                int idx = s[i] - 'a';
                if (curr->childs[idx] == NULL) {
                    curr->childs[idx] = new Node;
                }
                curr = curr->childs[idx];
                if (i == 0) {
                    curr->isEnd = true;
                }
            }
        }
    }

    bool query(char letter) {
        stream += letter;
        Node* curr = root;
        for (int i = stream.length() - 1; i >= 0; i--) {
            int idx = stream[i] - 'a';
            curr = curr->childs[idx];
            if (curr == NULL) {
                return false;
            }
            if (curr->isEnd) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end
