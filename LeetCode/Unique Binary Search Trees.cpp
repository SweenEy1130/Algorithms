// Definition for binary tree
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return *generateTrees(1, n);
    }

    vector<TreeNode *> * generateTrees(int start, int end) {
        vector<TreeNode *> * subTrees = new vector<TreeNode *>();
        if (start > end){
            subTrees->push_back(NULL);
            return subTrees;
        }

        for (int i = start; i <= end; i++){
            vector<TreeNode *> * leftTree = generateTrees(start, i - 1);
            vector<TreeNode *> * rightTree = generateTrees(i+1, end);

            for (int u = 0; u < leftTree->size(); ++u)
            {
                for (int v = 0; v < rightTree->size(); ++v)
                {
                    TreeNode * pNode = new TreeNode(i);
                    pNode->left = (*leftTree)[u];
                    pNode->right = (*rightTree)[v];
                    subTrees->push_back(pNode);
                }
            }
        }
        return subTrees;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<TreeNode *> ans = s.generateTrees(4);
    for (int i = 0; i < ans.size(); i++){
        TreeNode * tnode = ans[0];

        vector<TreeNode *> queue = new vector<TreeNode*>();
        queue.push_back(tnode);

        while (queue.size() != 0){
            tnode = queue[0];
            cout << tnode->val << "-";
            queue.erase(0);
            if (tnode->left != NULL){
                queue.push_back(tnode->left);
            }
            if (tnode->right != NULL){
                queue.push_back(tnode->right);
            }
        }
    }
    return 0;
}