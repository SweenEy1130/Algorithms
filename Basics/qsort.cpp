// Reference site: http://java.dzone.com/articles/algorithm-week-quicksort-three
#include <iostream>
using namespace std;
// Single pivot
/*void quicksort(int * a, int first, int last){
    if (first < last){
        int pivot = a[first], i = first, j = last, tmp;
        while(i < j){
            while(a[i] <= pivot) ++i;
            while(a[j] > pivot) --j;
            if (i < j){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        a[first] = a[j];
        a[j] = pivot;
        quicksort(a, first, j-1);
        quicksort(a, j+1, last);
    }
    return;
}*/

// Three way partition
/*void quicksort(int a[], int first, int last){
    if (first >= last) return;
    int pivot = a[first];
    int right = last, left = first, idx = first + 1;
    while (idx <= right){
        if (a[idx] < pivot)
            swap(a[idx++], a[left++]);
        else if (a[idx] > pivot){
            while (a[right] > pivot) right--;
            swap(a[idx], a[right--]);
        }
        else idx++;
    }
    quicksort(a, first, left - 1);
    quicksort(a, right + 1, last);
    return;
}*/


// Double pivots
void quicksort(int a[], int first, int last){
    if (first >= last) return;
    int pivot1 = a[first], pivot2 = a[last];
    int right = last-1, left = first+1, idx = first + 1;
    if (pivot1 > pivot2)
    {
        swap(pivot1, pivot2);
        swap(a[first], a[last]);
    }
    while (idx <= right){
        if (a[idx] < pivot1) {
            swap(a[idx++], a[left++]);
        }
        else if (a[idx] > pivot2) {
            swap(a[idx], a[right--]);
        }else
            idx++;
    }

    swap(a[first], a[--left]);
    swap(a[last], a[++right]);

    quicksort(a, first, left - 1);
    quicksort(a, left + 1, right - 1);
    quicksort(a, right + 1, last);
    return;
}

int main(int argc, char const *argv[])
{
    int A[] = {3,45,3,23,12,23,23,7,90,8};
    quicksort(A, 0, 9);
    for (int i = 0; i < 10; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}