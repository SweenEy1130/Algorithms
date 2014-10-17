#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int tmp;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > 0 && A[i] < n && A[i] != i && A[A[i]] != A[i]){
                tmp = A[i];
                A[i] = A[A[i]];
                A[A[i]] = tmp;
                i--;
            }
        }
        for (int i = 1; i < n; ++i){
            if (A[i] < i){
                return i;
            }
        }

        return A[0] == n? n+1:n;
    }
};