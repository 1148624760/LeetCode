
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<tuple<int, int, int>> vt;

    void dfs(TreeNode* node, int col, int row) {
        if (node->left) {
            vt.push_back(make_tuple(col - 1, row + 1, node->left->val));
            dfs(node->left, col - 1, row + 1);
        }
        if (node->right) {
            vt.push_back(make_tuple(col + 1, row + 1, node->right->val));
            dfs(node->right, col + 1, row + 1);
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vt.push_back(make_tuple(0, 0, root->val));
        dfs(root, 0, 0);
        sort(vt.begin(), vt.end());

        vector<vector<int>> ret;
        int colValue = INT_MIN;
        vector<int> temp;

        for (auto& [col, row, val]: vt) {
            if (col == colValue) {
                temp.push_back(val);
            }
            else {
                if (!temp.empty()) {
                    ret.push_back(temp);
                    temp.clear();
                }
                temp.push_back(val);
                colValue = col;
            }
        }
        if (!temp.empty())
            ret.push_back(temp);

        return ret;
    }
};
