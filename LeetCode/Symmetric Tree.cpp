/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *a, TreeNode *b){
        if (a==NULL && b == NULL) return true;
        if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
            return false;
        if (a->val != b->val) return false;
        return isSymmetric(a->left , b->right) && isSymmetric(a->right, b->left);
    }
};