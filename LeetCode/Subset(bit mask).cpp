class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(S.begin(), S.end());
        int total_case = 1 << S.size();
        for (int i = 0; i < total_case; ++i)
        {
            vector<int> row;
            for (int j = 0; j < S.size(); j++)
                if ((i & (1 << j)) > 0)
                    row.push_back(S[j]);
            result.push_back(row);
        }
        return result;
    }
};