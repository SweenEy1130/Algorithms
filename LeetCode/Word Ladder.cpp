#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
struct qnode
{
    string word;
    int length;
};
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int word_len, word_cnt = dict.size();
        queue<qnode> q;
        qnode tnode;
        tnode.word = start;
        tnode.length = 1;
        q.push(tnode);
        while (!q.empty()){
            string head = q.front().word;
            int depth = q.front().length;
            cout << head << " " << depth << endl;
            q.pop();
            word_len = head.length();
            for (int i = 0; i < word_len; ++i)
            {
                char ch = head[i];
                for (char c = 'a'; c <= 'z'; c++){
                    if (ch != c){
                        head[i] = c;
                        if (head == end) return depth+1;
                        if (dict.find(head) != dict.end()){
                            qnode tnode;
                            tnode.word = head;
                            tnode.length = depth + 1;
                            q.push(tnode);
                            // dict.erase(head);
                        }
                    }
                }
                head[i] = ch;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    cout << sol.ladderLength("hit", "cog", dict) << endl;
    return 0;
}