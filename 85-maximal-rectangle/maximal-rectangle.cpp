class Solution {
public:

    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;

                maxArea = max(maxArea,
                              heights[element] * width);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;

            maxArea = max(maxArea,
                          heights[element] * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int m = matrix.size();

        if(m == 0) return 0;

        int n = matrix[0].size();

        vector<int> heights(n, 0);

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans,
                      largestRectangleArea(heights));
        }

        return ans;
    }
};