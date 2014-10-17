#include <iostream>
#include <map>

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL){
            return NULL;
        }
        RandomListNode * tmp = head, *new_list;
        map<RandomListNode *, RandomListNode *> hashtable;

        while (tmp != NULL){
            if (hashtable.find(tmp) == hashtable.end()){
                new_list = new RandomListNode(tmp->label);
                hashtable.insert(make_pair(tmp, new_list));
            }else{
                new_list = hashtable[tmp];
            }

            if (tmp->next != NULL){
                if (hashtable.find((tmp->next)) == hashtable.end()){
                    new_list->next = new RandomListNode(tmp->next->label);
                    hashtable.insert(make_pair((tmp->next), new_list->next));
                }else{
                    new_list->next = hashtable[(tmp->next)];
                }
            }
            if (tmp->random != NULL){
                if (hashtable.find((tmp->random)) == hashtable.end()){
                    new_list->random = new RandomListNode(tmp->random->label);
                    hashtable.insert(make_pair((tmp->random), new_list->random));
                }else{
                    new_list->random = hashtable[(tmp->random)];
                }
            }

            tmp = tmp->next;
        }
        return hashtable[head];
    }

    void printRandomList(RandomListNode *head){
        while (head != NULL){
            cout << head->label << "\trand:\t";
            if (head->random != NULL)
            {
                cout << head->random->label << endl;
            }else{
                cout << "NULL\n";
            }
            head = head->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    RandomListNode * a = new RandomListNode(1), * b = new RandomListNode(2), * c = new RandomListNode(3), * d = new RandomListNode(4), * e = new RandomListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    a->random = c;
    b->random = d;

    s.printRandomList(s.copyRandomList(a));
    return 0;
}