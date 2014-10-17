class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        std::map<int, bool> map;
        for (int i = 0; i < num.size(); ++i)
            if (map.find(num[i]) == map.end())
                map[num[i]] = true;

        int k, cnt, ans = INT_MIN;
        for (int i = 0; i < num.size(); ++i)
        {
            if (map.find(num[i]) != map.end() && map.find(num[i] - 1) == map.end()){
                k = i; cnt = 1;
                while (map.find(num[k] + 1) != map.find()){
                    k++;
                    cnt++;
                }
                ans = (ans >= cnt)?ans:cnt;
            }
        }
        return ans;
    }
};

