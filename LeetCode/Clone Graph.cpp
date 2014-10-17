#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for undirected graph.
**/
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
        queue<UndirectedGraphNode *> nodeQ;
        UndirectedGraphNode * tnode, * tneighbor, * new_node = new UndirectedGraphNode(node->label);
        nodeQ.push(node);
        nodeMap[node] = new_node;

        while (!nodeQ.empty()){
            tnode = nodeQ.front();
            nodeQ.pop();
            for (int i = 0; i < tnode->neighbors.size() ;++i)
            {
                tneighbor = tnode->neighbors[i];
                if (nodeMap.find(tneighbor) == nodeMap.end()){
                    UndirectedGraphNode * new_neighbor = new UndirectedGraphNode(tnode->neighbors[i]->label);
                    nodeMap[tneighbor] = new_neighbor;

                    nodeMap[tnode]->neighbors.push_back(new_neighbor);
                    nodeQ.push(tneighbor);
                }else{
                    nodeMap[tnode]->neighbors.push_back(nodeMap[tneighbor]);
                }
            }
        }
        return new_node;
    }
};

int main(int argc, char const *argv[])
{
    UndirectedGraphNode * a, *b, *c;
    a = new UndirectedGraphNode(0);
    b = new UndirectedGraphNode(1);
    c = new UndirectedGraphNode(2);
    a->neighbors.push_back(b);
    a->neighbors.push_back(c);
    b->neighbors.push_back(c);
    c->neighbors.push_back(c);

    Solution s;
    UndirectedGraphNode * node = s.cloneGraph(a) , * tnode, * tneighbor;
    cout << "finish clone\n";
    map<UndirectedGraphNode *, bool> nodeVisited;
    queue<UndirectedGraphNode *> nodeQ;
    nodeQ.push(node);
    nodeVisited[node] = true;
    while (!nodeQ.empty()){
        tnode = nodeQ.front();
        nodeQ.pop();
        for (int i = 0; i < tnode->neighbors.size() ;++i)
        {
            tneighbor = tnode->neighbors[i];
            cout << tneighbor->label << ", ";
            if (nodeVisited.find(tnode) == nodeVisited.end()){
                nodeVisited.insert(make_pair(tnode, true));
            }else{
                nodeQ.push(tneighbor);
            }
        }
        cout << endl;
    }
    return 0;
}