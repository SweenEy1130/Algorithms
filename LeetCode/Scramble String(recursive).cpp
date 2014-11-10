class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int l = s1.size();
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        for (int i = 1; i < l; ++i){
            if (isScramble(s1.substr(0, i), s2.substr(0,i)) &&
                isScramble(s1.substr(i, l-i), s2.substr(i, l-i))) return true;
            if (isScramble(s1,substr(0, i), s2.substr(l-i, i)) &&
                isScramble(s1.substr(i, l-i), s2.substr(0,l-i))) return true;
        }
        return false;
    }
};
