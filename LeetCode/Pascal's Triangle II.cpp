#include <cstddef>
#include <stdio.h>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ivec(rowIndex, 0);
        ivec[0] = 1;
        for (vector<int>::size_type ix = 1; ix < ivec.size(); ix++){
            for (vector<int>::size_type iy = ix; iy > 0; iy--){
                ivec[iy] = ivec[iy] + ivec[iy-1];
            }
        }
        return ivec;
    }
    void printList(vector<int> ivec){
        for(vector<int>::size_type i = 0; i != ivec.size(); ++i)
            printf("%d\t", ivec[i]);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.printList(s.getRow(11));
    return 0;
}