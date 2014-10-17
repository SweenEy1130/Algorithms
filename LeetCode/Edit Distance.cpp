#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        int f[1000][1000];
        for (int i = 0; i<= l2; ++i)
            f[0][i] = i;
        for (int i = 0; i<= l1; ++i)
            f[i][0] = i;
        for (int i = 1; i <= l1; ++i)
        {
            for (int j = 1; j <= l2; ++j)
            {
                if (word1[i-1] == word2[j-1]){
                    f[i][j] = f[i-1][j-1];
                }else{
                    int dist = 2147483647;
                    if (i-1 >= 0 && f[i-1][j] < dist){
                        dist = f[i-1][j];
                    }
                    if (j-1 >= 0 && f[i][j-1] < dist){
                        dist = f[i][j-1];
                    }
                    if (j-1 >= 0 && i-1 >= 0 && f[i-1][j-1] < dist){
                        dist = f[i-1][j-1];
                    }
                    f[i][j] = dist + 1;
                }
            }
        }

        return f[l1][l2];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    string word1("heal");
    string word2("wheel");
    cout << word1 << endl;
    cout << word2 << endl;
    cout << s.minDistance(word1, word2);
    return 0;
}