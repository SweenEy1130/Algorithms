#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        if (l1 == 0 || l2 == 0)
            return "";
        string ans, num3 = "", tail = "";
        for (int i = l2-1; i >= 0; --i)
        {
            ans = multi(num1 , num2[i]) + tail;
            tail += '0';
            cout << ans << '\t' << num3 << endl;
            num3 = add(num3, ans);
        }
        return num3;
    }

    string multi(string num1, char multi){
        string ans = "";
        int m = multi - '0', carry = 0, mod;
        for (int i = num1.length() - 1; i >= 0; i--){
            mod = ((num1[i]-'0') * m + carry) % 10;
            ans = char(int('0') + mod) + ans;
            carry = ((num1[i]-'0') * m + carry) / 10;
        }
        if (carry != 0){
            ans = char(int('0')+ carry) + ans;
        }
        return ans;
    }

    string add(string num1 ,string num2){
        int l1 = num1.length(), l2 = num2.length();
        int maxLen = (l1>l2)?l1:l2;
        string ans="";
        int multi, carry=0;
        for (int i = 1; i <= maxLen; i++){
            if (l1 >= i && l2 >= i){
                multi = ((num1[l1-i]-'0') + (num2[l2-i] - '0') + carry) % 10;
                carry = ((num1[l1-i]-'0') + (num2[l2-i] - '0') + carry) / 10;
                ans = char(int('0')+multi) + ans;
            }else
            if (l1 >= i){
                multi = ((num1[l1-i]-'0') + carry) % 10;
                carry = ((num1[l1-i]-'0') + carry) / 10;
                ans = char(int('0') + multi) + ans;
            }else
            if (l2 >= i){
                multi = ((num2[l2-i]-'0') + carry) % 10;
                carry = ((num2[l2-i]-'0') + carry) / 10;
                ans = char(int('0') + multi) + ans;
            }
        }
        if (carry != 0){
            ans = char(int('0')+ carry) + ans;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.multiply("123","456") << endl;
    return 0;
}