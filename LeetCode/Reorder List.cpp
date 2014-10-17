#include <cstddef>
#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        ListNode * mid = findMiddle(head);
        ListNode * tail = mid->next;
        mid->next = NULL;
        tail = reverseList(tail);
        ListNode * tNode = head;
        ListNode * start = head;
        start = start->next;
        while (tNode != NULL){
            tNode->next = tail;
            if (tail != NULL) tail = tail->next;
            tNode = tNode->next;

            if (tNode != NULL){
                tNode->next = start;
                if (start != NULL) start = start->next;
                tNode = tNode->next;
            }
        }
        // printList(head);
    }

    ListNode * findMiddle(ListNode *head){
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL){
            fast = fast->next;
            if (fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode * reverseList(ListNode *head){
        ListNode * preNode = NULL;
        ListNode * curNode = head;
        ListNode * postNode;
        while (curNode != NULL){
            postNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = postNode;
        }
        return preNode;
    }

    void printList(ListNode *head){
        while (head != NULL){
            printf("%d\t", head->val);
            head = head->next;
        }
        printf("\n");
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    // n4->next = n5;
    s.reorderList(n1);
    return 0;
}