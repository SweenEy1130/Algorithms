#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        if (l==0) return 0;
        int * f = new int[l+1];
        for (int i = 0; i < l+1; ++i)
            f[i] = 0;
        f[0] = 1;
        for (int i = 1; i < l+1; ++i)
        {
            // 1 digit
            if (s[i-1] - '0')
                f[i] += f[i-1];
            // 2 digit
            if (i > 1){
                int val2 = s[i-1] - '0' + 10 * (s[i-2] - '0');
                if (val2 > 9 && val2 < 27)
                    f[i] += f[i-2];
            }
        }
        return f[l];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string ss("0000");
    printf("%d\n", s.numDecodings(ss));
    return 0;
}