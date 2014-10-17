class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0)
            return 0;
        int maxArea = 0, l = height.size();
        int * row = new int[l+1];

        row[l] = 0;
        stack<int> st;
        for (int i = 0; i < l+1; ++i)
        {
            if (i < l) row[i] = height[i];

            if (st.empty() || row[st.top()] <= row[i])
                st.push(i);
            else{
                while(!st.empty() && row[st.top()] > row[i]){
                    int t = st.top();
                    st.pop();
                    int area = row[t] * ((st.empty())?i:(i - st.top() - 1));
                    maxArea = (maxArea < area)?area: maxArea;
                }
                st.push(i);
            }
        }

        return maxArea;
    }
};