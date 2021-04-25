#include"head.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (res == nums[i]) count++;
            else count--;
            if (count == 0) res = nums[i + 1];
        }
        return res;
    }
};