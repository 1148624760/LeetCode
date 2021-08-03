// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n, k;
        while (i <= j) {
            k = i + (j - i) / 2;
            if (isBadVersion(k) == true) {
                j = k - 1;
            }
            else {
                i = k + 1;
            }
        }
        return i;
    }
};
