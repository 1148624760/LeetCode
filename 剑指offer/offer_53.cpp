#include"head.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int front = 0, end = nums.size() - 1, mid;
        int left = -1, right = -1;
        while (front <= end) {
            mid = (front + end) / 2;
            if (nums[mid] > target) end = mid - 1;
            else if (nums[mid] < target) front = mid + 1;
            else {
                right = mid;
                front = mid + 1;
            }
        }
        if (right == -1) return 0;
        front = 0;
        while (front <= end) {
            mid = (front + end) / 2;
            if (nums[mid] > target) end = mid - 1;
            else if (nums[mid] < target) front = mid + 1;
            else {
                left = mid;
                end = mid - 1;
            }
        }
        return right - left + 1;
    }
};