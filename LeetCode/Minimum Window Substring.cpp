#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int len_s = S.length(), len_t = T.length();
        if (len_t == 0 || len_s == 0) return "";

        bool alphaMarker[196] = {false};
        int alphaFreq[196] = {0};
        int stringFreq[196] = {0};
        int t_sum = 0;

        for (int i = 0; i < len_t; ++i){
            if (!alphaMarker[T[i]])
                t_sum++;
            alphaFreq[T[i]]++;
            alphaMarker[T[i]] = true;
        }

        int start = 0, minWin = len_s, counter_t = 0, minStart = -1;
        for (int i = 0; i < len_s; ++i){
            if (alphaMarker[S[i]] == true){
                stringFreq[S[i]]++;
                if (stringFreq[S[i]] == alphaFreq[S[i]])
                    counter_t++;
            }
            while (start < len_s &&
                    (!alphaMarker[S[start]] ||
                    alphaFreq[S[start]] < stringFreq[S[start]])
                ){
                stringFreq[S[start]]--;
                start++;
            }
            if (counter_t == t_sum && i-start+1 <= minWin){
                minWin = i - start + 1;
                minStart = start;
            }
        }
        if (minStart == -1) return "";
        return S.substr(minStart, minWin);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // string ss("ADOBECODEBANC"), tt("ABC");
    string ss("aa"), tt("aa");
    cout << s.minWindow(ss, tt) << endl;
    return 0;
}