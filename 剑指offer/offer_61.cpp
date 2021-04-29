#include "head.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> st;
        int min = 13, max = 0;
        for (int i : nums) {
            if (i != 0) {
                if (i < min) min = i;
                if (i > max) max = i;
                if (!st.insert(i).second) return false;
            }
        }
        if ((max - min) < 5) return true;
        else return false;
    }
};