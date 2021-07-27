#include"head.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 1;
        int left = 0; 
        long long val = 0;
        for (int i = 1; i < nums.size(); i++) {
            val += (long long)(nums[i] - nums[i - 1]) * (i - left);
            while (val > k) {
                val -= nums[i] - nums[left];
                left++;
            }
            ret = max(ret, i - left + 1);
        }
        return ret;
    }
};