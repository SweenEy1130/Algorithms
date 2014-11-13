class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string tstr;
        vector<string> ret;
        int l = s.length();
        if (l <= 12 && l >= 4){
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 3; j++)
                    for (int m = 1; m <= 3; m++)
                        for (int n = 1; n <= 3; n++)
                            if (i + j + m + n == l){
                                int idx = 0;
                                string ans;
                                string tmp = s.substr(idx, i);
                                if (stoi(tmp) < 256 && (i == 1 || tmp[0] != '0')) ans.append(tmp.append("."));
                                else continue;
                                idx += i;
                                tmp = s.substr(idx, j);
                                if (stoi(tmp) < 256 && (j == 1 || tmp[0] != '0')) ans.append(tmp.append("."));
                                else continue;
                                idx += j;
                                tmp = s.substr(idx, m);
                                if (stoi(tmp) < 256 && (m == 1 || tmp[0] != '0')) ans.append(tmp.append("."));
                                else continue;
                                idx += m;
                                tmp = s.substr(idx, n);
                                if (stoi(tmp) < 256 && (n == 1 || tmp[0] != '0')) ret.push_back(ans.append(tmp));
                            }
        }
        return ret;
    }
};