#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL)
            return -1;
        int hl = strlen(haystack), nl = strlen(needle);
        if (nl == 0) return 0;
        if (hl == 0) return -1;

        // Compute prefix for the pattern
        int * next = new int [nl];
        next[0] = -1;
        int cur = 0, k = -1;
        while (cur < nl-1)
        {
            if (k == -1 || needle[cur] == needle[k])
                if (needle[++cur] == needle[++k])
                    next[cur] = next[k];
                else
                    next[cur] = k;
                // next[++cur] = ++k;
            else
                k = next[k];
        }

        cur = 0;
        k = 0;
        while (cur < hl)
        {
            if (k == -1 || haystack[cur] == needle[k]){
                cur++;k++;
            }else{
                k = next[k];
            }
            if (k == nl){
                return cur-k;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // char * haystack = "bbc abcdab abcdabcdabde", * needle = "abcdabd";
    // char * haystack = "mississip", * needle = "issip";
    char * haystack = "abacbcdhiabab", * needle = "abab";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}