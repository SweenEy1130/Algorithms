#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        int gt = n-1, lt = 0, i = lt;
        while(i <= gt){
            if (A[i] == 0){
                swap(A[lt++], A[i++]);
            }else if (A[i] == 1){
                i++;
            }else if (A[i] == 2){
                swap(A[gt--], A[i]);
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 2, A[] = {2,1};
    sol.sortColors(A, n);
    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << endl;
    }
    return 0;
}