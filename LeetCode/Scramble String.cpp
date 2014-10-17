class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int l = s1.size();
        int f[100][100][100] = {false};
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < l; ++j)
                if (s1[i] == s2[j]) f[1][i][j] = true;

        for (int k = 2; k <= l; k++)
            for (int i = 0; i < l-k+1; ++i)
                for (int j = 0; j < l-k+1; ++j)
                    for (int t = 1; t < k; t++){
                            f[k][i][j] |= f[t][i][j] && f[k-t][i+t][j+t];
                            f[k][i][j] |= f[t][i][j+k-t] && f[k-t][i+t][j];
                        }

        return f[l][0][0];
    }
};
