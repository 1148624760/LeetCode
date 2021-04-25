#include"head.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1;
        long t = n; 
        if (n < 0) {
            x = 1 / x;
            t = -t;
        }
        double ans = 1;
        while (t > 0) {
            if ((1 & t) == 1) {
                ans *= x;
            }
            t >>= 1;
            x *= x;
        }
        return ans;
    }
};