class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0,r = n-1,mxArea = 0;
        while(l < r){
            if(height[l] <= height[r]){
                mxArea = max(mxArea,min(height[l],height[r])*(r - l));
                l++;
            }
            else{
                mxArea = max(mxArea,min(height[l],height[r])*(r - l));
                r--;
            }
        }
        return mxArea;
    }
};