/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;

        TreeLinkNode *front, *tail, *head = NULL;
        tail = front = root;

        while (front != NULL){
            if (front->left != NULL){
                tail->next = front->left;
                tail = tail->next;
                if (head == NULL)
                    head = front->left;
            }
            if (front->right != NULL){
                tail->next = front->right;
                tail = tail->next;
                if (head == NULL)
                    head = front->right;
            }

            if (front->next == head){
                front->next = NULL;
                front = head;
                head = NULL;
            }else{
                front = front->next;
            }
        }

        return;
    }
};