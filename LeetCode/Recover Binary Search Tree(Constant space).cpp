#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
private:
    TreeNode * prev;
public:
    void recoverTree(TreeNode *root) {
        TreeNode * a, * b;
        prev = 0;
        dfs(root, a, b);
        int t = a->val;
        a->val = b->val;
        b->val = t;
        return;
    }

    void dfs(TreeNode * root, TreeNode * &a, TreeNode * &b){
        if (root == 0)
            return;
        dfs(root->left, a, b);

        if (prev != 0 && prev->val > root->val){
            if (a == 0) {a = prev;b=root;}
            else b = root;
        }
        prev = root;

        dfs(root->right, a, b);

        return;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode * a = new TreeNode(0);
    a->left = new TreeNode(1);
    Solution sol;
    cout << a->val << endl;
    cout << a->left->val << endl;
    sol.recoverTree(a);
    cout << a->val << endl;
    cout << a->left->val << endl;
    return 0;
}