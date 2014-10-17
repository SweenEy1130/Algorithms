#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int idx = 0;
        ListNode * root = new ListNode(-1);
        root->next = head;
        ListNode * start;
        ListNode * cur = head;
        ListNode * prev = root;
        while (cur != NULL){
            idx++;
            if (idx >= m && idx <= n && m != n){
                if (idx == m){
                    start = prev;
                }
                if (idx == n){
                    if (start->next != NULL)
                        start->next->next = cur->next;
                    start->next = cur;
                }
                ListNode * post = cur->next;
                cur->next = prev;
                prev = cur;
                cur = post;
            }else{
                prev = cur;
                cur = cur->next;
            }

        }
        return root->next;
    }
};
int main(int argc, char const *argv[])
{
    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    ListNode * c = new ListNode(3);
    ListNode * d = new ListNode(4);
    ListNode * e = new ListNode(5);
    a->next = b;
    // b->next = c;
    c->next = d;
    d->next = e;
    Solution sol;
    ListNode *head = sol.reverseBetween(a, 1, 2);
    while(head!=NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}