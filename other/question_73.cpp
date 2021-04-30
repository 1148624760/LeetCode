#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    unordered_map<int, int> index;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
            return nullptr;

        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        TreeNode *root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        int size_right_subtree = inorder_right - inorder_root;

        root->left = build(preorder, inorder, )
    }
};
