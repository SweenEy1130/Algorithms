class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<vector<int> > result;
        sort(S.begin(), S.end());
        int total_case = 1 << S.size();
        for (int i = 0; i < total_case; ++i)
        {
            vector<int> row;
            for (int j = 0; j < S.size(); j++)
                if ((i & (1 << j)) > 0)
                    row.push_back(S[j]);
            sort(row.begin(),row.end());
            result.insert(row);
        }
        vector<vector<int> > ret(result.begin(), result.end());
        return ret;
    }
};