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
private:
    int maxSum;
public:
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        maxSum = root->val;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode * tnode){
        if (tnode == NULL) return 0;
        int t1 = 0, t2 = 0;
        t1 = dfs(tnode->left);
        t2 = dfs(tnode->right);
        int tmp = tnode->val;
        tmp = max(tmp, tmp + t1);
        tmp = max(tmp, tmp + t2);
        maxSum = max(maxSum, tmp);
        return max(tnode->val , tnode->val + max(t1,t2));
    }

    int max(int a, int b){
        return (a>b)?a:b;
    }
};