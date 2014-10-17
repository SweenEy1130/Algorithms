#include <vector>
#include <stddef.h>
using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    vector<int> io;
    vector<int> po;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        po = preorder;
        io = inorder;
        int inl = io.size(), pol = po.size();
        return buildTree(0, inl-1, 0, pol - 1);

    }

    TreeNode *buildTree(int io_start, int io_end, int po_start, int po_end){
        if (io_start > io_end || po_start > po_end)
            return NULL;
        int idx, rt = po[po_start];
        TreeNode *root = new TreeNode(rt);
        for (int i = io_start; i <= io_end; i++)
            if (io[i] == rt){
                idx = i;
                break;
            }
        root->left = buildTree(io_start, idx-1, po_start + 1, po_start + idx - io_start);
        root->right = buildTree(idx+1, io_end, po_start + idx-io_start + 1, po_end);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> a,b;
    a.push_back(2);
    a.push_back(1);
    b.push_back(2);
    b.push_back(1);
    sol.buildTree(a,b);
    return 0;
}