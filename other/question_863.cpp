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
    unordered_map<int, TreeNode*> um;
    vector<int> ret;

    void findNext(TreeNode* node, TreeNode* from, int k) {
        if (k == 0) {
            ret.push_back(node->val);
            return;
        }
        if (node->left && node->left != from) {
            findNext(node->left, node, k - 1);
        }
        if (node->right && node->right != from) {
            findNext(node->right, node, k - 1);
        }
        TreeNode* parent = um[node->val];
        if (parent && parent != from) {
            findNext(parent, node, k - 1);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> qts;
        qts.push(root);
        um[root->val] = nullptr;
        while (!qts.empty()) {
            TreeNode* node = qts.front();
            qts.pop();
            if (node->left) {
                um[node->left->val] = node;
                qts.push(node->left);
            }
            if (node->right) {
                um[node->right->val] = node;
                qts.push(node->right);
            }
        }

        findNext(target, nullptr, k);

        return ret;
    }
};