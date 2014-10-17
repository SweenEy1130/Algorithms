#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long a = abs(dividend);
        unsigned long b = abs(divisor);

        unsigned long long ret = 0;
        unsigned long long k = 1, t = b;

        for (;t <= a;t = t<<1,k <<= 1)
            continue;

        t >>= 1;
        k >>= 1;

        while(a >= t && k > 0){
            a -= t;
            ret += k;
            while (a > 0 && a < t){
                t >>= 1;
                k >>= 1;
            }
        }

        return ((dividend > 0)^(divisor > 0))?(-ret):ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    long long a = -2147483648, b=1;
    cout << s.divide(a,b) << endl;
    return 0;
}