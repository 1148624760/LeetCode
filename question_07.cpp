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
    unordered_map<int, int> index;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return build_tree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_right < preorder_left)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_left]);
        int pos = index[preorder[preorder_left]];
        int subtree_left_size = pos - inorder_left; 
        root->left = build_tree(preorder, inorder, preorder_left + 1, preorder_left + subtree_left_size, inorder_left, pos - 1);
        int subtree_right_size = inorder_right - pos;
        root->right = build_tree(preorder, inorder, preorder_left + subtree_left_size + 1, preorder_right, pos + 1, inorder_right);    
        return root;
    }
};