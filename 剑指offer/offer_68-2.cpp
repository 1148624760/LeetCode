#include "head.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, TreeNode*> um1;
    unordered_map<int, bool> um2;
    void dfs(TreeNode* root) {
        if (root->left) {
            um1[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            um1[root->right->val] = root;
            dfs(root->right);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        um1[root->val] = nullptr;
        dfs(root);
        while (p) {
            um2[p->val] = true;
            p = um1[p->val];
        }
        while (q) {
            if (um2[q->val]) return q;
            q = um1[q->val];
        }
        return nullptr;
    }
};