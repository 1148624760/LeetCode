#include"head.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = nums.size() - 1;
        int ret = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            ret = max(ret, nums[i] + nums[j]);
            j--;
        }
        return ret;
    }
};