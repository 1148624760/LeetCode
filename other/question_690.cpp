#include "head.h"


class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// 深度优先搜索 dfs
class Solution {
private:
    unordered_map<int, Employee*> um;
    int res = 0;
    void dfs(int id) {
        res += um[id]->importance;
        if (!um[id]->subordinates.empty()) {
            for (auto i : um[id]->subordinates) {
                dfs(i);
            }
        } else {
            return;
        }
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto i : employees) {
            um[i->id] = i;
        }
        dfs(id);
        return res;
    }
};

/* 暴力递归 
class Solution {
private:
    int func(vector<Employee*> employees, int id) {
        int val;
        Employee* temp = nullptr;
        for (auto i : employees) {
            if (i->id == id) {
                val = i->importance;
                temp = i;
                break;
            }
        }
        if (!temp->subordinates.empty()) {
            int sum = 0;
            for (auto i : temp->subordinates) {
                sum += func(employees, i);
            }
            return val + sum;
        }
        return val;
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        res = func(employees, id);
        return res;
    }
}; */