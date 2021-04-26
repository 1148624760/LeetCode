#include"head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int res, kValue;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        if (kValue == 0) return;
        if (--kValue == 0) res = root->val;
        dfs(root->left);
    }

public:
    int kthLargest(TreeNode* root, int k) {
        kValue = k;
        dfs(root);
        return res;
    }
};