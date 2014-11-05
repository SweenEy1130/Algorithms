/**
 * Definition for binary tree
 * struct TreeNode {
 *	int val;
 *	TreeNode *left;
 *	TreeNode *right;
 *	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode *> preStack;
		TreeNode * head;
		if (root == 0) return result;
		preStack.push(root);

		while (!preStack.empty()){
			head = preStack.top();
			result.push_back(head->val);
			if (head->left != 0){
				preStack.push(head->left);
				head = head->left;
			}else{
				preStack.pop();
				while (head->right == 0 && !preStack.empty()){
					head = preStack.top();
					preStack.pop();
				}
				if (head->right != 0){
					preStack.push(head->right);
					head = head->right;
				}
			}
		}
		return result;
	}
};

// Shorter one
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
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*> nodeStack;
		vector<int> result;
		if(root==NULL) return result;
		nodeStack.push(root);
		while(!nodeStack.empty()){
			TreeNode* node= nodeStack.top();
			result.push_back(node->val);
			nodeStack.pop();

			if(node->right)
			nodeStack.push(node->right);

			if(node->left)
			nodeStack.push(node->left);
		}
		return result;
	}
};