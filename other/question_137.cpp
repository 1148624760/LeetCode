#include "head.h"

// 位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int temp = 0;
            for (int j : nums) {
                j >>= i;
                temp = temp + (j & 1); 
            }
            temp = temp % 3;
            temp <<= i;
            res |= temp;
        }
        return res;
    }
};