// 暴力排序
/*
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int begin = -1, end = -1;
        vector<int> numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != numsSorted[i]) {
                begin = i;
                break;
            }
        }

        if (begin == -1) {
            return 0;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != numsSorted[i]) {
                end = i;
                break;
            }
        }
        
        return end - begin + 1;
    }
};
*/

// 双指针
class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            int begin = -1, end = -1;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] >= nums[i - 1]) {
                    continue;
                }
                else {
                    begin = i - 1;
                    break;
                }
            } 

            if (begin == -1) {
                return 0;
            }

            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i] <= nums[i + 1]) {
                    continue;
                }
                else {
                    end = i + 1;
                    break;
                }
            }
            
            int front = begin, rear = end;

            for (; begin <= end; begin++) {
                while (front != 0 && nums[begin] < nums[front - 1]) {
                    front--;
                }
                while (rear != nums.size() - 1 && nums[begin] > nums[rear + 1]) {
                    rear++;
                }
            }
        
            return rear - front + 1;
        }
};
