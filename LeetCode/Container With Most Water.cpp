class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int left = 0, right = n - 1, k;
        int maxWater = 0;
        while (left < right){
            maxWater = max(maxWater, (right - left) * min(height[right], height[left]));
            if (height[left] < height[right]){
                k = left;
                while (height[k] <= height[left]) k++;
                left = k;
            }else{
                k = right;
                while (height[k] <= height[right]) k--;
                right = k;
            }
        }
        return maxWater;
    }
};