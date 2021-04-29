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

// 一次遍历
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else break;
        }      
        return root;
    }
};

/* 两次遍历 
class Solution {
private:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> res;
        while (root != target) {
            res.push_back(root);
            if (target->val < root->val) root = root->left;
            else root = root->right;
        }
        res.push_back(root);
        return res;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = getPath(root, p);
        vector<TreeNode*> path2 = getPath(root, q);
        TreeNode* ans;
        int minLength = min(path1.size(), path2.size());
        for (int i = 0; i < minLength; ++i) {
            if (path1[i] == path2[i]) ans = path1[i];
            else break;
        }
        return ans;
    }
}; */