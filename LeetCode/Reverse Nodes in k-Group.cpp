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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) return head;
        ListNode * dummy = new ListNode(-1), *tnode = head, *pnode, *cnode;
        ListNode * start;
        int count;
        dummy->next = head;
        start = pnode = dummy;
        while (tnode != NULL){
            count = 0;
            while (tnode != NULL && count < k){
                cnode = tnode;
                tnode = tnode->next;
                cnode->next = pnode;
                pnode = cnode;
                count++;
            }
            if (count < k){
                for (int i = 0; i < count; ++i){
                    pnode = cnode->next;
                    cnode->next = tnode;
                    tnode = cnode;
                    cnode = pnode;
                }
                break;
            }
            pnode = start->next;
            start->next->next = tnode;
            start->next = cnode;
            start = pnode;
        }
        return dummy->next;
    }
};