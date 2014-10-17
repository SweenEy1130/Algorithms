#include <map>
#include <list>
#include <iostream>

using namespace std;

struct Node {
    int key, value;
    Node(int k, int v) : key(k), value(v) {};
};

class LRUCache {
    private:
        size_t mCapacity;
        size_t mSize;
        unordered_map<int, list<Node>::iterator> mKey;
        list<Node> mValue;
        typedef list<Node>::iterator value_iterator;

        // move the element i, to the end
        value_iterator moveBack(value_iterator i) {
            Node node = *i;
            mValue.erase(i);
            return mValue.insert(mValue.end(), node);
        }
    public:
        LRUCache(size_t capacity) : mCapacity(capacity), mSize(0) {
        }

        int get(int key)
        {
            unordered_map<int, list<Node>::iterator>::iterator iter = mKey.find(key);
            if (iter == mKey.end()) {
                // cout << "No such node: " << key << endl;
                return -1;
            }
            iter->second = moveBack(iter->second);
            // cout << "Got " << iter->second->value << " for key: " << key << endl;
            return iter->second->value;
        }

        void set(int key, int value)
        {
            list<Node>::iterator iNode;
            unordered_map<int, value_iterator>::iterator j = mKey.find(key);

            if (j != mKey.end()) {
                // cout << "Already existed, key: " << key << endl;
                iNode = moveBack(j->second);
                // cout << "update from " << iNode->value << " to " << value << endl;
                iNode->value = value;
                j->second = iNode;

                return;
            }

            if (mCapacity <= mSize) {
                // The least used node is at the first place.
                iNode = mValue.begin();
                // cout << "Exceeded, the beginning node (" << iNode->key << ", " << iNode->value << ")." << endl;

                j = mKey.find(iNode->key);
                iNode = moveBack(iNode);
                iNode->key = key;
                iNode->value = value;

                mKey.erase(j);
                mKey.insert(pair<int, value_iterator>(key, iNode));
                // cout << "Replace the least used node with (" << key << ", " << value << ")" << endl;
                return;
            }

            // Add new node as the capacity is not exceeded.
            Node node(key, value);
            iNode = mValue.insert(mValue.end(), node);
            mKey.insert(pair<int, value_iterator>(key, iNode));
            // cout << "Added a brand new node: (" << key << ", " << value << ")" << endl;
            mSize++;
        }
};