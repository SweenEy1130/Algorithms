class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        std::unordered_map<int, bool> map;
        for (int i = 0; i < num.size(); ++i)
            if (map.find(num[i]) == map.end())
                map[num[i]] = true;

        int k, cnt, ans = INT_MIN;
        for (int i = 0; i < num.size(); ++i){
            if (map.find(num[i]) != map.end() && map.find(num[i] - 1) == map.end()){
                k = num[i]; cnt = 1;
                while (map.find(k + 1) != map.end()){
                    k = k++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

