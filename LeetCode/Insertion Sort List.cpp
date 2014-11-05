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
    ListNode *insertionSortList(ListNode *head) {
        int len = 0;
        ListNode * tmp, *pre, * new_head = new ListNode(-1);
        while (head != 0)
        {
            tmp = new_head;
            while (tmp != NULL){
                pre = tmp;
                tmp = tmp->next;
                if (tmp == 0){
                    pre->next = head;
                    head = head->next;
                    pre->next->next = 0;
                }else if (tmp->val > head->val){
                    pre->next = head;
                    head = head->next;
                    pre->next->next = tmp;
                    break;
                }
            }
        }
        return new_head->next;
    }
};