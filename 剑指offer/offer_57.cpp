#include "head.h"

// 双指针相撞
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int front = 0, end = nums.size() - 1;
        while (front < end) {
            if (nums[front] + nums[end] < target) front++;
            else if (nums[front] + nums[end] > target) end--;
            else return {nums[front], nums[end]};
        }
        return {};
    }
};