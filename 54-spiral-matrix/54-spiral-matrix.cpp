class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lc=0;
        int ur=0;
        int lr=matrix.size()-1;
        int rc=(matrix[0].size())-1;
        int i=0;
        int p=0;
        vector<int> ans;
        while(lc<=rc && ur<=lr){
            for(i = lc;i <= rc;i++){
                ans.push_back(matrix[ur][i]);
            }
            ur++;
            for(i = ur;i <= lr;i++){
                ans.push_back(matrix[i][rc]);
            }
            rc--;
            if(lc <= rc && ur <= lr){
                for(i = rc;i >= lc;i--){
                    ans.push_back(matrix[lr][i]);
                }
                lr--;
            }
            if(ur <= lr && lc <= rc){
                for(i = lr;i >= ur;i--){
                    ans.push_back(matrix[i][lc]);
                }
                lc++;
            }
        }
        return ans;
    }
};