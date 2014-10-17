#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<int> * blank_x = new vector<int>;
        vector<int> * blank_y = new vector<int>;

        for (int i = 0 ; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] == '.'){
                    blank_x->push_back(i);
                    blank_y->push_back(j);
                }
            }
        }

        Sudoku(board, 0, blank_x, blank_y);
        return;
    }

    bool Sudoku(vector<vector<char> > &board, int idx, vector<int> * blank_x, vector<int> * blank_y){
        if (idx == blank_x->size()){
            return true;
        }
        int i = (*blank_x)[idx], j = (*blank_y)[idx];
        if (board[i][j] == '.'){
            for (int k = 1; k < 10; k++){
                char cur = (char)(int('0')+k);
                if (checkAvailablity(board, i, j, cur)){
                    board[i][j] = cur;
                    if (Sudoku(board, idx+1, blank_x, blank_y)){
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    bool checkAvailablity(vector<vector<char> > &board, int x, int y, char k){
        for (int i = 0; i < 9; i++)
            if (board[i][y] == k && i != x){
                return false;
            }
        for (int j = 0; j < 9; j++)
            if (board[x][j] == k && j != y){
                return false;
            }
        int xsq, ysq;
        xsq = (x / 3) * 3;
        ysq = (y / 3) * 3;
        for (int i = xsq; i < xsq + 3; i++)
            for (int j = ysq; j < ysq + 3; j++){
                if (board[i][j] == k && i != x && j != y)
                    return false;
            }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    char v[9][9] = {{'5','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}
                };
    vector<vector<char> > board;
    for (int i=0 ; i < 9; i++){
        vector<char> vv;
        for (int j = 0; j < 9; j++){
            vv.push_back(v[i][j]);
        }
        board.push_back(vv);
    }
    s.solveSudoku(board);
    for (int ix=0 ; ix < 9; ix++){
        for (int jx = 0; jx < 9; jx++)
            cout << board[ix][jx] << " ";
        cout << endl;
    }
    return 0;
}