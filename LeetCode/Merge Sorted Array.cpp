class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int idx_a = m - 1, idx_b = n - 1, idx_c = m + n - 1;

        while(idx_a >= 0 || idx_b >= 0){
            if (idx_a < 0){
                A[idx_c] = B[idx_b];
                idx_b--;
            }else if (idx_b < 0){
                break;
            }else if (A[idx_a] > B[idx_b]){
                A[idx_c] = A[idx_a];
                idx_a--;
            }else if (A[idx_a] <= B[idx_b]){
                A[idx_c] = B[idx_b];
                idx_b--;
            }
            idx_c--;
        }

        return;
    }
};