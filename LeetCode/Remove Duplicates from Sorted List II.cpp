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
        ListNode *pre_node, *tnode = head, *root = new ListNode(-1);
        pre_node = root;
        root->next = head;
        while (tnode != NULL){
            while (tnode->next != NULL && tnode->val == tnode->next->val){
                tnode = tnode->next;
            }
            if (pre_node->next == tnode){
                pre_node = pre_node->next;
            }else{
                pre_node->next = tnode->next;
            }
            tnode = tnode->next;
        }
        return root->next;
    }
};