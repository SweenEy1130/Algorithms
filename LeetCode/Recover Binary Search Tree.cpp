#include <iostream>
#include <climits>
using namespace std;
/**
 * Definition for binary tree
 **/
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recover(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b) {
        if (root)
        {
            recover(root->left, pre, a, b);

            if (root->val < pre->val)
            {
                if (!a) a = pre; //a should change once.
                b = root; //b could change twice.
            }
            pre = root;

            recover(root->right, pre, a, b);
        }
    }
    void recoverTree(TreeNode *root) {
        if (!root) return;

        TreeNode p(numeric_limits<int>::min());
        TreeNode *a, *b, *pre;
        a = b = 0;
        pre = &p;
        recover(root, pre, a, b);
        if (a && b)
        {
            swap(a->val, b->val);
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode * t1 = new TreeNode(4),
            * t2 = new TreeNode(2),
            * t3 = new TreeNode(10),
            * t4 = new TreeNode(1),
            * t5 = new TreeNode(3),
            * t6 = new TreeNode(1),
            * t7 = new TreeNode(7);
    // t1->left = t2;
    t1->right = t3;
    // t2->left = t4;
    // t2->right = t5;
    // t3->left = t6;
    t3->right = t7;
    s.recoverTree(t1);

    cout << t3->val << endl;
    cout << t6->val << endl;
    return 0;
}