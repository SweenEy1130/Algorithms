#include <iostream>
using namespace std;
int QuickSelection(int * a, int first, int last, int k){
    if (first < last){
        int pivot = a[first], i = first, j = last, tmp;
        while(i < j){
            while(a[i] <= pivot) ++i;
            while(a[j] > pivot) --j;
            if (i <= j){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        a[first] = a[j];
        a[j] = pivot;
        if (j > k)
            return QuickSelection(a, first, j-1, k);
        else if (j < k)
            return QuickSelection(a, j+1, last, k);
        else
            return a[j];
    }else{
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {3,45,3,23,12,534,23,7,90,8};
    int ans = QuickSelection(A, 0, 9, 8);
    cout << ans << endl;
    return 0;
}