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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy_small = new ListNode(-1), *dummy_large = new ListNode(-1);
        ListNode *tmp_head = head, *tmp_small = dummy_small, * tmp_large = dummy_large;
        while (tmp_head != 0){
            if (tmp_head->val < x){
                tmp_small->next = tmp_head;
                tmp_small = tmp_small->next;
            }else{
                tmp_large->next = tmp_head;
                tmp_large = tmp_large->next;
            }
            tmp_head = tmp_head->next;
        }
        tmp_small->next = dummy_large->next;
        tmp_large->next = 0;
        return dummy_small->next;
    }
};