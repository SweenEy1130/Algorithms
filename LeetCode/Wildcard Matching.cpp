/*
For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
       if there is no *,  return false;
       if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.
*/
#include <iostream>
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;

        while (*s != '\0'){
            if (*s == *p || *p == '?'){
                s++;p++;
            }else if (*p == '*'){
                star = ++p;
                ss = s;
            }else if (star){
                s = ++ss;
                p = star;
            }else{
                return false;
            }

        }

        //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    std::cout << sol.isMatch("aabbc", "a*bc") << std::endl;
    return 0;
}