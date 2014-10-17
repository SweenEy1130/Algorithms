#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        vector<int> temp(size, 0);
        // cout << "Size: " << size << endl;
        for (int i = 0 ; i < size; i++){
            temp[i] = triangle[size-1][i];
        }
        for (int i = size - 1; i > 0; i--){
            for (int j = 0; j < i; j++){
                temp[j] = (temp[j] < temp[j+1])?(temp[j]+triangle[i-1][j]):(temp[j+1]+triangle[i-1][j]);
            }
        }
        return temp[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int> > triangle;
    for (int c = 0; c < 2; c++){
        vector<int> t;
        for (int i = 0; i <= c; i++){
            t.push_back(i+1+c);
        }
        triangle.push_back(t);
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j <= i; j++){
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}