#include <iostream>
int binarySearch(int A[] , int n, int target){
    int left = 0, right = n - 1, mid;
    while (left <= right){
        mid = (right - left) / 2 + left;
        if (A[mid] == target){
            return mid;
        }else if (A[mid] < target){
            left = mid + 1;
        }else if (A[mid] > target){
            right = mid - 1;
        }
    }
    return (target > A[mid])?left:mid;
}

int main(int argc, char const *argv[])
{
    int A[] = {2,3,4,8,12,24,32,39,55,72}, n = 10, target = 8;
    std::cout << binarySearch(A, n, target) << std::endl;
    return 0;
}