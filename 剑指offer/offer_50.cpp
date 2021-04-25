#include"head.h"

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> um;
        for (char i : s) {
            um[i]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (um[s[i]] == 1) return s[i];
        }
        return ' ';
    }
};