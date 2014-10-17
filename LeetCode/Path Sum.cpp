#include <iostream>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        TreeNode * head = root;

        return dps(head, sum);
    }

    bool dps(TreeNode *tnode, int remain) {
        if (tnode == NULL) return false;
        if (isLeaf(tnode) && tnode->val == remain){
            return true;
        }else
        if ((isLeaf(tnode) && tnode->val != remain)){
            return false;
        }else{
            bool left = false, right = false;
            if (tnode->left != NULL){
                left = dps(tnode->left, remain - tnode->val);
            }
            if (tnode->right != NULL){
                right = dps(tnode->right, remain - tnode->val);
            }
            return left || right;
        }
    }

    bool isLeaf(TreeNode *tnode){
        if (tnode->left == NULL && tnode->right == NULL){
            return true;
        }else{
            return false;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *t1 = new TreeNode(-2), *t2 = new TreeNode(4),
            *t3 = new TreeNode(-3), *t4 = new TreeNode(11), *t5 = new TreeNode(13),
            *t6 = new TreeNode(4), *t7 = new TreeNode(7), *t8 = new TreeNode(1),
            *t9 = new TreeNode(1);
    // t1->left = t2;
    t1->right = t3;
    // t2->left = t4;
    // t3->left = t5;
    // t3->right = t6;
    // t4->right = t8;
    // t4->left = t7;
    // t6->right = t9;

    cout << s.hasPathSum(t1, -5) << endl;
    return 0;
}