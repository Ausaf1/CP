class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0,i=0,j=n-1;
        while(i<j){
            int area = (j-i)*min(height[i],height[j]);
            maxArea = max(area,maxArea);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxArea;
    }
};