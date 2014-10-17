#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode * tailPtr = 0, * slowPtr = head, * fastPtr = head;
        int cnt = 0;
        while (cnt < k){
            if (fastPtr->next == NULL){
                tailPtr = fastPtr;
                tailPtr->next = head;
            }
            fastPtr = fastPtr->next;
            cnt++;
        }
        if (tailPtr == 0){
            while (fastPtr->next != tailPtr){
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
        }else{
            while (fastPtr != tailPtr){
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
        }
        fastPtr->next = head;
        head = slowPtr->next;
        slowPtr->next = NULL;

        return head;
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
    // c->next = d;
    // d->next = e;
    Solution s;

    a = s.rotateRight(a, 1);
    while (a != NULL){
        cout << a->val << "->";
        a = a->next;
    }
    cout << endl;
    return 0;
}