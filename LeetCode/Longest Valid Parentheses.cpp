class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), startValid = -1, maxLength = 0;
        stack<int> ParStack;

        for (int i = 0; i < len; ++i){
            if (s[i] == '('){
                ParStack.push(i);
            }else if (!ParStack.empty() && s[i] == ')'){
                ParStack.pop();
                int t = (!ParStack.empty())?ParStack.top():startValid;
                maxLength = max(maxLength, i - t);
            }else{
                startValid = i;
            }
        }
        return maxLength;
    }
};