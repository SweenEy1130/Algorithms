class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length(), len_b = b.length(), carry=0;
        string c("");
        for (int i = 1; i <= max(len_a, len_b); ++i)
        {
            int t1 = 0, t2 = 0;
            if (len_a - i >= 0)
                t1 = a[len_a - i] - '0';
            if (len_b - i >= 0)
                t2 = b[len_b - i] - '0';
            c = char(carry^t1^t2 + '0') + c;
            carry = (t1+t2+carry) / 2;
        }
        if (carry != 0){
            c = char(carry+'0') + c;
        }
        return c;
    }
};