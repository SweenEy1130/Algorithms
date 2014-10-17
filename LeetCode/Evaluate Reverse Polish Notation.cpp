#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isOperator(string op){
        return (op == "+" || op == "-" || op == "*" || op == "/");
    }
    int evalRPN(vector<string> &tokens) {
        stack<string> st;
        for (int i = tokens.size()-1; i >= 0 ; --i)
        {
            if (!isOperator(tokens[i]) && !isOperator(st.top()) ){
                int a =stoi(tokens[i]), b = stoi(st.top());
                st.pop();
                string op = st.top();
                st.pop();
                if (op == "+"){
                    st.push(to_string(a+b));
                }else if (op == "-"){
                    st.push(to_string(a-b));
                }else if (op == "*"){
                    st.push(to_string(a*b));
                }else if (op == "/"){
                    st.push(to_string(a/b));
                }
            }else{
                st.push(tokens[i]);
            }
        }
        return st.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> tokens;
    tokens.push("2");
    tokens.push("1");
    tokens.push("+");
    tokens.push("3");
    tokens.push("*");
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}