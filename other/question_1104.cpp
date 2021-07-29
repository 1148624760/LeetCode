#include"head.h"

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        int n = 0;
        int s = 1;
        while (s <= label) {
            s *= 2;
            n++;
        }

        bool flag = true;
        while (n > 0) {
            if (flag) {
                ret.push_back(label);
            }
            else {
                ret.push_back((1 << n) + (1 << n - 1) - 1 - label);
            }
            label = label / 2;
            n--;
            flag = !flag;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};