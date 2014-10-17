#include <stddef.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int l=0;
        ListNode *t=head;
        while (t != NULL){
            t = t->next;
            l++;
        }
        if (l == 0) return NULL;

        return convertBST(head, 0, l-1);
    }

    TreeNode *convertBST(ListNode *& head, int start, int end){
        if (start > end)
            return NULL;
        int mid = (end-start)/2 + start;
        TreeNode * left = convertBST(head, start, mid-1);
        TreeNode * parent = new TreeNode(head->val);
        parent->left = left;
        head = head->next;
        parent->right = convertBST(head, mid+1, end);
        return parent;
    }
};

int main(int argc, char const *argv[])
{
    ListNode * a, *b,*c,*d;
    a = new ListNode(1);
    b = new ListNode(2);
    c = new ListNode(3);
    // d = new ListNode(4);
    a->next = b;
    b->next = c;
    // c->next = d;
    Solution sol;
    sol.sortedListToBST(a);
    return 0;
}