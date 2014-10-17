#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // even
        if ((m+n)%2==0) return (GetMedian(A, m, B, n, (m+n)/2)+GetMedian(A, m, B, n, (m+n)/2+1)) / 2.0;
        // odd
        else return GetMedian(A, m, B, n, (m+n)/2 + 1);
    }
    int GetMedian(int a[], int n, int b[], int m, int k)
    {
        // assert(a && b);
        if (n <= 0) return b[k-1];
        if (m <= 0) return a[k-1];
        if (k <= 1) return min(a[0], b[0]);
        if (b[m/2] >= a[n/2]){
             if ((n/2 + 1 + m/2) >= k)
                  return GetMedian(a, n, b, m/2, k);
             else
                  return GetMedian(a + n/2 + 1, n - (n/2 + 1), b, m, k - (n/2 + 1));
        }else{
          if ((m/2 + 1 + n/2) >= k)
               return GetMedian( a, n/2,b, m, k);
          else
               return GetMedian( a, n, b + m/2 + 1, m - (m/2 + 1),k - (m/2 + 1));
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int A[5] = {0,3,4,5,9}, B[5] = {1,2,6,7,8};
    int m = 5, n = 5;
    cout << s.findMedianSortedArrays(A,m,B,n) << endl;
    return 0;
}