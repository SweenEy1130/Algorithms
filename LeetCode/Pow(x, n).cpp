#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double ans;
        double pow_val[33];
        int pow_idx[33], idx = -1;
        long long longN;
        if (n == 0){
          return 1;
        }
        longN = n;
        if (longN > 0){
            ans = x;
        }
        else {
            ans = 1/x;
            longN = -longN;
        }
        for (long long i = 1; i < longN;)
        {
            // check overflow
            if (2 * i <= longN && 2 * i > i){
                idx++;
                pow_idx[idx] = i;
                pow_val[idx] = ans;
                ans *= pow_val[idx];
                i *= 2;
            }else if (i + pow_idx[idx] <= longN && i + pow_idx[idx] > i){
                ans *= pow_val[idx];
                i += pow_idx[idx];
            }else{
                idx--;
            }

        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.pow(-1, -2147483648) << endl;
    return 0;
}