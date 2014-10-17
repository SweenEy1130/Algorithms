class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;
        int h = grid.size(), w = grid[0].size();
        vector<int> dp(w, INT_MAX );
        dp[0] = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
            {
                if (j > 0) dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                else dp[j] += grid[i][j];
            }

        return dp[w-1];
    }
};