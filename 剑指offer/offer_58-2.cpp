#include "head.h"

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res;
        for (int i = n; i < n + s.size(); ++i) {
            res += s[i % s.size()];
        }
        return res;
    }
};