#include"head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;      // 如果头指针为空    
        queue<TreeNode*> queue;     // 辅助队列
        vector<int> temp;           // 中间变量
        bool flag = false;
        queue.push(root);           // 头指针入队
        while (!queue.empty()) {    // 队列非空时执行循环
            for (int i = queue.size(); i > 0; --i) {    // 当前所在层长度
                if (queue.front()) {
                    temp.push_back(queue.front()->val);
                    queue.push(queue.front()->left);
                    queue.push(queue.front()->right);
                }
                queue.pop();
            }
            if (flag) reverse(temp.begin(), temp.end());
            if (!temp.empty()) res.push_back(temp);
            temp.clear();
            flag = !flag;
        }
        return res;
    }
};