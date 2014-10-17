/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *pre_node, *tnode, *root = new ListNode(-1);
        root->next = head;
        pre_node = root;
        tnode = head;
        while (tnode != NULL){
            while (tnode->next != NULL && tnode->val == tnode->next->val){
                tnode = tnode->next;
            }
            pre_node->next = tnode;
            pre_node = tnode;
            tnode = tnode->next;
        }

        return root->next;
    }
};