#include <iostream>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
        S = "@" + S;
        T = "@" + T;
        int ls = S.length(), lt = T.length();
        if (ls == 0) return 0;
        if (lt == 0) return 1;
        int **f = new int * [ls];
        for (int i = 0; i < ls; ++i)
        {
            f[i] = new int[lt];
        }

        for (int i = 0; i < ls; ++i)
            for (int j = 0; j < lt; ++j)
                f[i][j] = 0;
        if (S[0] == T[0]){
            f[0][0] = 1;
        }
        for (int j = 0; j < lt; ++j)
            for (int i = j; i < ls; ++i)
            {
                if (i > 0)
                    f[i][j] += f[i-1][j];
                if (i > 0 && j > 0 && S[i] == T[j])
                    f[i][j] += f[i-1][j-1];
            }
/*        for (int i = 0; i < ls; ++i){
            for (int j = 0; j < lt; ++j)
                cout << f[i][j] << "\t";
            cout << endl;
        }*/
        return f[ls-1][lt-1];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.numDistinct("rabbbit", "rabit") << endl;
    return 0;
}