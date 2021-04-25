#include<head.h>

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int a = n / 3;
        int b = n % 3;
        int c = 1000000007;
        long ans = 1;
        for (int i = 0; i < a - 1; ++i) {
            ans = (ans * 3) % c;
        }
        if (b == 0) ans = ans * 3 % c;
        if (b == 1) ans = ans * 4 % c;
        if (b == 2) ans = ans * 6 % c;
        return int(ans);
    }
};