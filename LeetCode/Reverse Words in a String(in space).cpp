#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    void reverse(string &s, int start, int end){
        while (start < end)
            swap(s[start++], s[end--]);
    }
    void reverseWords(string &s) {
        int l = s.length(), k = 0, pos = 0;
        if (l == 0) return;
        while (s[k] == ' ') k++;
        s.erase(0, k);
        l -= k;
        k = 0;
        while (k < l){
            if (s[k] == ' ' && s[k+1] == ' '){
                s.erase(k, 1);
                l--;
            }else {
                k++;
            }
        }
        reverse(s, 0, l-1);
        k = 0;
        while (s[k] == ' ') k++;
        s.erase(0, k);
        l -= k;
        for (int i = 0; i <= s.length(); i++)
            if (s[i] == ' ' || i == s.length()){
                reverse(s, pos, i-1);
                pos = i+1;
            }
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    // string s("a");
    string s("  the sky is   blue  ");
    cout << s << endl;
    sol.reverseWords(s);
    cout << s << endl;
    return 0;
}