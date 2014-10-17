#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int lrow;
    int lcol;
public:
    bool exist(vector<vector<char> > &board, string word) {
        lrow = board.size();
        if (lrow == 0) return false;
        lcol = board[0].size();
        vector<vector<bool> > visited;
        for (int i = 0; i < lrow; ++i)
        {
            vector<bool> row;
            for (int j = 0; j < lcol; ++j)
                row.push_back(false);
            visited.push_back(row);
        }

        for (int i = 0; i < lrow; ++i)
            for (int j = 0; j < lcol; ++j)
                if (board[i][j] == word[0]){
                    visited[i][j] = true;
                    if (DFS(&board, &visited, i, j, 1, word))
                        return true;
                    visited[i][j] = false;
                }
        return false;
    }
    bool DFS(vector<vector<char> > *board, vector<vector<bool> > *visited, int xx, int yy, int idx, string word){
        // printVisited(visited);
        if (idx == word.length()) return true;
        if (xx+1 < lrow && !(*visited)[xx+1][yy] && (*board)[xx+1][yy] == word[idx]){
            (*visited)[xx+1][yy] = true;
            if (DFS(board, visited, xx+1, yy, idx+1, word))
                return true;
            (*visited)[xx+1][yy] = false;
        }
        if (xx-1 >= 0 && !(*visited)[xx-1][yy] && (*board)[xx-1][yy] == word[idx]){
            (*visited)[xx-1][yy] = true;
            if (DFS(board, visited, xx-1, yy, idx+1, word))
                return true;
            (*visited)[xx-1][yy] = false;
        }
        if (yy+1 < lcol && !(*visited)[xx][yy+1] && (*board)[xx][yy+1] == word[idx]){
            (*visited)[xx][yy+1] = true;
            if (DFS(board, visited, xx, yy+1, idx+1, word))
                return true;
            (*visited)[xx][yy+1] = false;
        }
        if (yy-1 >= 0 && !(*visited)[xx][yy-1] && (*board)[xx][yy-1] == word[idx]){
            (*visited)[xx][yy-1] = true;
            if (DFS(board, visited, xx, yy-1, idx+1, word))
                return true;
            (*visited)[xx][yy-1] = false;
        }
        return false;
    }
    void printVisited(vector<vector<bool> > *visited){
        for (int i = 0; i < lrow; ++i){
            for (int j = 0; j < lcol; ++j)
                cout << (*visited)[i][j] << "\t";
            cout << "\n";
        }
        cout << "---------\n";
    }
};

int main(int argc, char const *argv[])
{
    string st[3] = {"ABCE", "SFCS", "ADEE"};
    vector<vector<char> > board;
    for (int i = 0; i < 3; ++i)
    {
        vector<char> ans;
        for (int j = 0; j < 4; ++j)
        {
            ans.push_back(st[i][j]);
        }
        board.push_back(ans);
    }
    Solution s;
    string str("ABCB");
    cout << s.exist(board, str) << endl;
    return 0;
}