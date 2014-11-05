/**
 * Definition for binary tree
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode*> nodeStack;
		vector<int> result;
		if(root==NULL) return result;
		nodeStack.push(root);
		while(!nodeStack.empty()){
			TreeNode* node= nodeStack.top();
			result.push_back(node->val);
			nodeStack.pop();
			if(node->left)
			nodeStack.push(node->left);
			if(node->right)
			nodeStack.push(node->right);
		}
		reverse(result.begin(),result.end());
		return result;
	}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector <int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        s.push(root);

        while (!s.empty())
        {
            TreeNode* cur = s.top();

            //taking into account that if previous element coming from a subtree then it is either direct left or right child
            if (cur->right && cur->right == prev || !cur->right && cur->left == prev || !cur->left && !cur->right)
            {
                s.pop();
                res.push_back(cur->val);
                prev = cur;
                continue;
            }

            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
        }

        return res;
    }
};