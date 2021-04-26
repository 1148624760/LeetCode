#include"head.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


/* 辅助队列
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> stk, temp;
        stk.push(root);
        int res = 0;
        while(!stk.empty()) {
            while (!stk.empty()) {
                if (stk.front()->left) temp.push(stk.front()->left);
                if (stk.front()->right) temp.push(stk.front()->right);
                stk.pop();
            }
            stk = temp;
            temp = {};
            res++;
        }
        return res;
    }
}; */