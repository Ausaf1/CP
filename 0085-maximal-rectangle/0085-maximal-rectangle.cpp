class Solution {
private:
    int largestRectArea(vector<int> &heights){
        stack<int> st;
        int n = heights.size();
        vector<int> leftSmaller(n),rightSmaller(n);
        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1;i >= 0;i--){
           while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.top() - 1;
            st.push(i);
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            res = max(res,(rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(),col = matrix[0].size();
        vector<int> heights(col,0);
        int ans = 0;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans,largestRectArea(heights));
        }
        return ans;
    }
};