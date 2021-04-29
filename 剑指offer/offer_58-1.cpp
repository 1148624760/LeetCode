#include "head.h"

// 双指针
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0) return "";
        int end = s.size() - 1, front = end;
        string res;
        while (front >= 0) {
            while (front >= 0 && s[front] == ' ')
                front--;
            end = front;
            while (front >= 0 && s[front] != ' ')
                front--;
            if (front < end) {
                if (!res.empty()) res += " ";
                for (int i = front + 1; i < end + 1; ++i) {
                    res += s[i];
                }
            }
        }
        return res;
    }
};

/* 辅助栈 
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        stack<string> stk;
        string temp;
        for (auto i : s) {
            if (i != ' ') temp.push_back(i);
            else {
                if (!temp.empty()) stk.push(temp);
                temp.clear();
            }
        }
        if (!temp.empty()) {
            stk.push(temp);
            temp.clear();
        }
        if (stk.empty()) return "";
        temp = stk.top();
        stk.pop();
        while (!stk.empty()) {
            temp = temp + " " + stk.top();
            stk.pop();
        }
        return temp;
    }
}; */