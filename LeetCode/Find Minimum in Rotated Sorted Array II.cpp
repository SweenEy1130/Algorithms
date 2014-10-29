class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        if (n == 0) return 0;

        int left = 0, right = n-1, mid;
        while (right > 0 && num[right] == num[right-1]) right--;
        while (left < right && num[left] == num[right]) left++;
        if (num[left] <= num[right]) return num[left];

        while (right > left + 1){
            while (right > left + 1 && right > 0 && num[right] == num[right-1]) right--;
            int mid = (right - left) / 2 + left;

            if (num[left] > num[mid])
                right = mid;
            else
                left = mid;
        }

        return num[right];
    }
};