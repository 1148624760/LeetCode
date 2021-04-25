#include"head.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq; //大顶堆
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};