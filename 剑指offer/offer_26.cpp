#include"head.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isSubTree(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A || A->val != B->val) return false;
        return isSubTree(A->left, B->left) && isSubTree(A->right, B->right);
    }

public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A && B) && isSuvTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
