class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int matSize = mat.size()*mat[0].size();
      int newMatSize = r*c;
      if(matSize != newMatSize){
          return mat;
      }  
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                temp.push_back(mat[i][j]);
                if(temp.size()==c){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};