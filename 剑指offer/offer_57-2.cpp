#include "head.h"

// 双指针
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target == 1) return {};
        int front = 1, end = 2;
        vector<vector<int>> res;
        vector<int> temp;
        while(front < end) {
            int sum = (front + end) * (end - front + 1) / 2;
            if (sum > target) front++;
            else if (sum < target) end++;
            else {
                for (int i = front; i <= end; ++i) {
                    temp.push_back(i);
                }
                res.push_back(temp);
                temp.clear();
                front++;
            }
        }
        return res;
    }
};