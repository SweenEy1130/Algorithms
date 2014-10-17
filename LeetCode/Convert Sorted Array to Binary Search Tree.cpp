/**
 * Definition for binary tree
 */
#include <vector>
#include <stddef.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return ArrayToBST(num, 0, num.size()-1);
    }

    TreeNode *ArrayToBST(vector<int> &num, int start, int end){
        if (start > end)
            return NULL;
        int mid = (end-start)/2 + start;
        TreeNode * parent = new TreeNode(num[mid]);
        parent->left = ArrayToBST(num, start, mid-1);
        parent->right = ArrayToBST(num, mid+1, end);
        return parent;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4};
    vector<int> num(a,a+4);
    Solution sol;
    sol.sortedArrayToBST(num);

    return 0;
}