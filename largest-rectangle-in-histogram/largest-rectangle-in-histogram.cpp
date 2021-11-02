class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;
        int i = 0;
        while(i<heights.size()){
            if(s.empty() || heights[i]>heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                int k =s.top();
                s.pop();
                int currArea = heights[k]*(s.empty()?i:i-s.top()-1);
                maxArea = max(maxArea,currArea);
            }
        }
        return maxArea;
    }
};