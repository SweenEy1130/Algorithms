class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0, k, start = -1;
        bool visited[255] = {false};

        for (int i = 0; i < n; ++i){
            k = s[i];
            if (visited[k] == false){
                maxLen = max(i - start, maxLen);
                visited[k] = true;
            }else{
                while (s[start+1] != k){
                    visited[s[start]] = false;
                    start++;
                }
            }
        }
        return maxLen;
    }
};