#include "head.h"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> um;
        for (auto &i : wall) {
            int n = i.size();
            int sum = 0;
            for (int j = 0; j < n - 1; ++j) {
                sum += i[j];
                um[sum]++;
            }
        }
        int maxVal = 0;
        for (auto i : um) {
            maxVal = max(maxVal, i.second);
        }
        return wall.size() - maxVal;
    }
};