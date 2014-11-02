#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(const char *haystack, const char *needle) {
        int len_hay = strlen(haystack), len_ned = strlen(needle);
        if (len_ned == 0) return 0;
        int * PartialMatchTable = new int[len_ned];
        for (int i = 0; i < len_ned; ++i) PartialMatchTable[i] = 0;
        int cur = 1, matched = 0;
        while (cur < len_ned){
            if (cur+matched < len_ned && needle[cur + matched] == needle[matched]){
                PartialMatchTable[cur + matched] = ++matched;
            }else{
                if (matched > 0){
                    cur += matched - PartialMatchTable[matched - 1];
                    matched = PartialMatchTable[matched - 1];
                }else{
                    cur++;
                }

            }
        }

        cur = 0;
        matched = 0;
        while (cur < len_hay){
            if (cur+matched < len_hay && haystack[cur + matched] == needle[matched]){
                matched++;
            }else{
                if (matched > 0){
                    cur += matched - PartialMatchTable[matched - 1];
                    matched = PartialMatchTable[matched - 1];
                }else{
                    cur++;
                }

            }
            if (matched == len_ned)
                return cur;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    const char * haystack = "mississippi", * needle = "issipi";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}