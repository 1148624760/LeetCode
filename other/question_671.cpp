class Solution {
private:
    int ret = -1;
    int rootvalue;

    void dfs(TreeNode* &root) {
        if (!root)
            return;
        if (ret != -1 && root->val >= ret) 
            return;
        if (root->val > rootvalue && (root->val < ret || ret == -1)) {
            ret = root->val;
        }
        dfs(root->left);
        dfs(root->right);     
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        rootvalue = root->val;
        dfs(root);
        return ret;
    }
};