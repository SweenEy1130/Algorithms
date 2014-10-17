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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        queue<TreeNode *> q;
        queue<int> level;
        q.push(root);
        level.push(0);
        int cur_level, pre_level = 0;
        TreeNode * front, * tail;
        vector<int> row;
        bool flag = 0;
        while (!q.empty()){
            front = q.front();
            cur_level = level.front();
            q.pop();level.pop();

            if (pre_level != cur_level){
                if (flag)
                    reverse(row.begin(), row.end());
                flag = !flag;
                ans.push_back(row);
                row.clear();
            }
            row.push_back(front->val);

            if (front->left != NULL){
                q.push(front->left);
                level.push(cur_level+1);
            }

            if (front->right != NULL){
                q.push(front->right);
                level.push(cur_level+1);
            }
            pre_level = cur_level;
        }
        if (flag)
            reverse(row.begin(), row.end());
        ans.push_back(row);
        return ans;
    }
};