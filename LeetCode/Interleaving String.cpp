#include <iostream>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l1 + l2 != l3) return false;

        int **f = new int * [l1+1];
        for (int i = 0; i <= l1; ++i)
        {
            f[i] = new int[l2];
        }
        for (int i = 0; i <= l1; ++i)
            for (int j = 0; j <= l2; ++j)
                f[i][j] = 0;
        f[0][0] = 1;
        for (int i = 0; i <= l1; ++i)
            for (int j = 0; j <= l2; ++j){
                if (i > 0 && s1[i-1] == s3[i+j-1])
                    f[i][j] = f[i-1][j];
                else if (j > 0 && s2[j-1] == s3[i+j-1])
                    f[i][j] = f[i][j-1];
            }
/*        for (int i = 0; i <= l1; ++i){
            for (int j = 0; j <= l2; ++j)
                cout << f[i][j] << "\t";
            cout << endl;
        }*/
        return f[l1][l2];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << "ans:\t"<< s.isInterleave("aabcc", "dbbca","aadbbbaccc") << endl;
    cout << "ans:\t"<< s.isInterleave("aa", "ab","abaa") << endl;
    return 0;
}