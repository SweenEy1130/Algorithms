class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> result;
        dfs(ans, result, n, 1, k);
        return ans;
    }
    void dfs(vector<vector<int> > &ans, vector<int> result, int n, int num, int k){
        if (k == 0){
            ans.push_back(result);
            return;
        }

        if (num <= n-k+1 && k > 0){
            for (int i = num; i <= n; i++){
                result.push_back(i);
                dfs(ans, result, n, i+1, k-1);
                result.pop_back();
            }
        }
    }
};