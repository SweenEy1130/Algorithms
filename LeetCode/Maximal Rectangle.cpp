#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
private:
    int maxRec;
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        int height = matrix.size(), width = matrix[0].size();
        int * row = new int[width+1];
        for (int i = 0; i < width+1; ++i)
            row[i] = 0;
        maxRec = 0;

        for (int h = 0; h < height; h++){
            for (int w = 0; w < width+1; w++){
                if (w < width && matrix[h][w] == '1')
                    row[w]++;
                else
                    row[w] = 0;
            }

            stack<int> st1;
            for (int w = 0; w < width+1; w++){
                if (st1.empty() || row[st1.top()] <= row[w]){
                    st1.push(w);
                }else{
                    while (!st1.empty() && row[w] < row[st1.top()]){
                        int t = st1.top();
                        st1.pop();
                        int area = row[t] * ((st1.empty())?w:(w-st1.top()-1));
                        if (area > maxRec)
                            maxRec = area;
                    }
                    st1.push(w);
                }
            }
        }
        return maxRec;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string A[] = {"101011011111","110011101101",
                "010110100000","001110001010",
                "101011110101","111000000110",
                "010111011110","011001001101",
                "101010011010","011101000100"};
    // string A[] = {"01","01"};
    vector<vector<char> > mat;
    for (int i = 0; i < 10; ++i){
        vector<char> row;
        for (int j = 0; j < 12; ++j)
            row.push_back(A[i][j]);
        mat.push_back(row);
    }
    cout << sol.maximalRectangle(mat) << endl;
    return 0;
}