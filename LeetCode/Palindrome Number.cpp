#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0  || (x > 0 && x % 10 == 0))
            return false;
        int u = x, v = 0;
        while (u >= v){
            v = 10 * v + u % 10;
            // Odd
            if (u == v) return true;
            u = u / 10;
            // Even
            if (u == v) return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isPalindrome(1023201) << endl;
    return 0;
}