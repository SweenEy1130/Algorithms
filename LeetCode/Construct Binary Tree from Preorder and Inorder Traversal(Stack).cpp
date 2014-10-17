class Solution {
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        int i=0,j=0;
        TreeNode *root=new TreeNode(0x80000000);
        TreeNode *pp=NULL,*ptr=root;
        stack<TreeNode*> sn;
        sn.push(root);
        while (j<in.size()) {
            if (sn.top()->val==in[j]) {
                pp=sn.top();
                sn.pop();
                j++;
            } else if (pp) {
                ptr=new TreeNode(pre[i]);
                pp->right=ptr;pp=NULL;
                sn.push(ptr);
                i++;
            } else {
                ptr=new TreeNode(pre[i]);
                sn.top()->left=ptr;
                sn.push(ptr);
                i++;
            }
        }
        ptr=root->left;
        delete root;
        return ptr;
    }
};