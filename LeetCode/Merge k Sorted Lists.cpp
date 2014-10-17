#include <iostream>
#include <vector>
#include <queue>
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
    struct CompareNode {
        bool operator()(ListNode* const & p1, ListNode* const & p2) {
            return p1->val > p2->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();

        priority_queue<ListNode *, vector<ListNode *>, CompareNode> pq;
        for (int i = 0; i < k; ++i)
            if (lists[i]) pq.push(lists[i]);

        ListNode * dummy = new ListNode(-1), *head = dummy;
        while (!pq.empty()){
            head->next = pq.top();
            pq.pop();
            head = head->next;
            if (head->next != NULL)
                pq.push(head->next);
        }

        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode * a = new ListNode(1), * b = new ListNode(2), *c = new ListNode(3);
    vector<ListNode *> lists;
    a->next = b;
    b->next = c;
    lists.push_back(a);
    Solution sol;
    ListNode * ans = sol.mergeKLists(lists);
    while(ans!=NULL){
        cout <<ans->val << endl;
        ans = ans->next;
    }
    return 0;
}