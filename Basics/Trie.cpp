struct Node{
    char data;
    bool mark;
    vector<Node> children;

    Node(char c){
        data = c;
        mark = false;
    }

    getNode()
};
class Trie
{
private:
    Node * root;
public:
    Trie(){
        root = new Node(' ');
    };

    void insert(String s){
        Node cur = root;
        if (s.length() == 0)
            cur.mark = true;

        for (int i = 0; i < s.length(); ++i)
        {
            Node n = cur.getNode(s[i]);
        }
    }

    ~Trie();

};