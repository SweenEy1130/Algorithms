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
    bool isBalanced(TreeNode *root) {
        int ans = dfs(root);
        return (ans > -1)?1:0;
    }
    int dfs(TreeNode * root){
        if (root == NULL) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        if (l == -1 || r == -1 || abs(l-r) > 1) return -1;

        return max(l,r) + 1;
    }
};