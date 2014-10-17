#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:    
    vector<vector<int> > allPath;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> tPath;
        dps(root, sum, tPath);
        // printAllPath();
        return allPath;
    }

    bool dps(TreeNode *tnode, int remain, vector<int> tPath) {
        if (tnode == NULL) return false;
        tPath.push_back(tnode->val);
        if (isLeaf(tnode) && tnode->val == remain){
            allPath.push_back(tPath);
            return true;
        }else
        if ((isLeaf(tnode) && tnode->val != remain)){
            return false;
        }else{
            bool left = false, right = false;
            if (tnode->left != NULL){
                left = dps(tnode->left, remain - tnode->val, tPath);
            }
            if (tnode->right != NULL){
                right = dps(tnode->right, remain - tnode->val, tPath);
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

    void printAllPath(){
        for (vector<int>::size_type i = 0; i != allPath.size(); ++i)
        {
            for (vector<int>::size_type j = 0; j != allPath[i].size(); ++j){
                cout << allPath[i][j] << '\t';
            }
            cout << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *t1 = new TreeNode(5), *t2 = new TreeNode(4),
            *t3 = new TreeNode(8), *t4 = new TreeNode(11), *t5 = new TreeNode(13),
            *t6 = new TreeNode(4), *t7 = new TreeNode(7), *t8 = new TreeNode(2),
            *t9 = new TreeNode(5);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t4->right = t8;
    t4->left = t7;
    t6->right = t9;

    s.pathSum(t1, 22);
    return 0;
}