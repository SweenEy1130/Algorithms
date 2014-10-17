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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3 = new ListNode(-1), * tmp = l3;
        int val1, val2;
        while (l1 != NULL || l2 != NULL){
            val1 = (l1)?l1->val:INT_MAX;
            val2 = (l2)?l2->val:INT_MAX;
            if (val1 < val2){
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        return l3->next;
    }
};