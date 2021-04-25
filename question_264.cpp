#include<vector>

class Solution {
public:
    int minArray(vector<int>& numbers) {
        return get_min(numbers, 0, numbers.size() - 1);
    }

    int get_min(vector<int> numbers, int left, int right) {
        int mid = (left + right) / 2;
        if (numbers[right] < numbers[left] && numbers[left] < numbers[mid])
            return get_min(numbers, mid, right);
        if (numbers[mid] < numbers[right] && numbers[right] < numbers[left])
            return get_min(left, mid);
        return numbers[left];
    }
};