#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int l;
public:
    int totalNQueens(int n) {
        l = n;
        vector<bool> row, col, slope_down, slope_up;
        for (int i = 0; i < n; ++i)
        {
            row.push_back(true);
            col.push_back(true);
        }
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            slope_down.push_back(true);
            slope_up.push_back(true);
        }
        int ans = solveNQueens(0, row, col, slope_down, slope_up);
        return ans;
    }

    int solveNQueens(int x, vector<bool> row, vector<bool> col, vector<bool> slope_down, vector<bool> slope_up)
    {
        int ans = 0;
        if (x >= l) return 1;
        for (int y = 0; y < l; y++){
            if (row[x] && col[y] && slope_up[x+y] && slope_down[l+x-y-1]){
                row[x] = false;
                col[y] = false;
                slope_up[x+y] = false;
                slope_down[l+x-y-1] = false;
                ans += solveNQueens(x+1, row, col,slope_down,slope_up);
                row[x] = true;
                col[y] = true;
                slope_up[x+y] = true;
                slope_down[l+x-y-1] = true;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.totalNQueens(13) << endl;
    return 0;
}