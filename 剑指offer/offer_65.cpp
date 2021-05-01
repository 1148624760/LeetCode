#include "head.h"

// 位运算实现加法
class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int t = a ^ b;
            b = (unsigned int)(a & b) << 1; // 负数左移会出错
            a = t;
        }
        return a;
    }
};