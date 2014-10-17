#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int col, row = matrix.size(), direction = 1;
        vector<int> ans;
        if (row == 0){
            return ans;
        }
        col = matrix[0].size();

        vector<vector<bool> > visited;
        for (int i = 0 ; i < row; i++){
            vector<bool> tmp;
            for (int j = 0; j < col; j++){
                tmp.push_back(false);
            }
            visited.push_back(tmp);
        }

        int x = 0, y = 0;
        for (int i = 0; i < row * col; ++i)
        {
            // 1 for right, 2 for left, 3 for up, 4 for down
            ans.push_back(matrix[x][y]);
            visited[x][y] = true;
            if (direction == 1 && y != col-1 && visited[x][y+1] == false){
                y++;
            }else
            if (direction == 1 && (y == col-1 || visited[x][y+1] == true)){
                x++;
                direction = 4;
            }else
            if (direction == 2 && y != 0 && visited[x][y-1] == false){
                y--;
            }else
            if (direction == 2 && (y == 0 || visited[x][y-1] == true)){
                x--;
                direction = 3;
            }else
            if (direction == 3 && x != 0 && visited[x-1][y] == false){
                x--;
            }else
            if (direction == 3 && (x == 0 || visited[x-1][y] == true)){
                y++;
                direction = 1;
            }else
            if (direction == 4 && x != row-1 && visited[x+1][y] == false){
                x++;
            }else
            if (direction == 4 && (x == row-1 || visited[x+1][y] == true)){
                y--;
                direction = 2;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int> > matrix;
    int m[2][3]={{1,2,3},{4,5,6}};
    for (int i = 0; i < 2; ++i){
        vector<int> row;
        for (int j = 0; j < 3; ++j)
        {
            row.push_back(m[i][j]);
        }
        matrix.push_back(row);
    }
    vector<int> ans = s.spiralOrder(matrix);
    for (int i = 0; i < 6; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}