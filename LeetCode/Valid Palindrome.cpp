#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 0) return true;
        int start = 0, end = len - 1;
        while(start < end){
            while(start < end && !isAlphanumeric(s[start])) start++;
            while(start < end && !isAlphanumeric(s[end])) end--;
            if (tolower(s[start]) != tolower(s[end])) return false;
            start++;end--;
        }
        return true;
    }
    bool isAlphanumeric(char c){
        if ((c >= '0' && c <='9') || (c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))
            return true;
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}