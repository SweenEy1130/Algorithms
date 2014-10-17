#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL)
            return NULL;
        int hl = strlen(haystack), nl = strlen(needle);
        if (nl == 0) return haystack;
        if (hl == 0) return NULL;

        // Compute prefix for the pattern
        int * pi = new int [nl+1];
        pi[1] = 0;
        int k = 0;
        for (int q = 1; q < nl; q++){
            while(k > 0 && needle[k] != needle[q])
                k = pi[k];
            if (needle[k] == needle[q])
                k++;
            pi[q+1] = k;
        }

        // KMP
        int q = 0;
        for (int i = 0; i < hl; i++){
            while (q > 0 && needle[q] != haystack[i])
                q = pi[q];
            if (haystack[i] == needle[q])
                q++;
            if (q == nl){
                return haystack + i - nl + 1;
            }
        }

        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    char * haystack = "bbc abcdab abcdabcdabde", * needle = "abcdabd";
    // char * haystack = "mississippi", * needle = "mississippi";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}