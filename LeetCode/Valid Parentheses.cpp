class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;

        for (int i = 0; i < s.length(); ++i){
            switch (s[i]){
                case '(':
                case '[':
                case '{':
                    parentheses_stack.push(s[i]);
                    break;
                case ')':
                    if (!parentheses_stack.empty() && parentheses_stack.top() == '('){
                        parentheses_stack.pop();
                    }else{
                        return false;
                    }
                    break;
                case ']':
                    if (!parentheses_stack.empty() && parentheses_stack.top() == '['){
                        parentheses_stack.pop();
                    }else{
                        return false;
                    }
                    break;
                case '}':
                    if (!parentheses_stack.empty() && parentheses_stack.top() == '{'){
                        parentheses_stack.pop();
                    }else{
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        if (parentheses_stack.empty()){
            return true;
        }else{
            return false;
        }
    }
};
