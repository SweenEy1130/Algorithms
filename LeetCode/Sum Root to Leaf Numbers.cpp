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
    int sumNumbers(TreeNode *root) {
        if (root == 0) return 0;
        int sumVal = 0;
        dfs(root, sumVal, 0);
        return sumVal;
    }

    void dfs(TreeNode * tnode, int &sumVal, int curVal){
        int newVal = curVal*10+tnode->val;
        // Check leaf node
        if (tnode->left == 0 && tnode->right == 0){
            sumVal += newVal;
        }
        if (tnode->left != 0) dfs(tnode->left, sumVal, newVal);
        if (tnode->right != 0) dfs(tnode->right, sumVal, newVal);
    }
};