class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int n = matrix.size(),m = matrix[0].size();
        int left = 0,top = 0,bottom = n-1,right = m-1;
        while(left <= right && top <= bottom){
            for(int i = left;i <= right;i++){
                spiral.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i <= bottom;i++){
                spiral.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right;i >= left;i--){
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom;i >= top;i--){
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return spiral;
    }
};