#include"head.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == mid) left = mid + 1;
            else right = mid - 1;
        }
        if (nums[mid] == mid) return mid + 1;
        else return mid;
    }
};