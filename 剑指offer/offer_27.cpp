#include"head.h"


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int front = 0;
        int i = 0, j = 0;
        while (i < pushed.size() && j < popped.size()) {
            if (s.empty() || s.top() != popped[j]) {
                s.push(pushed[i]);
                i++;
            } else {
                s.pop();
                j++;
            }
        }
        if (s.empty()) return true;
        else return false;
    }
};

int main() {
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    Solution* s = new Solution();
    cout << s->validateStackSequences(pushed, popped);
    return 0;
}
