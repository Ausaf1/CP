class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0,r = mat.size() - 1;
        int mid,peak = 0;
        while(l <= r){
            mid =  (l+r)>>1;
            peak = 0;
            for(int i = 0;i < mat[mid].size();i++){
                if(mat[mid][peak] < mat[mid][i])
                    peak = i;
            }
            if(mid < r && mat[mid][peak] < mat[mid+1][peak])
                l = mid + 1;
            else if(mid > l && mat[mid][peak] < mat[mid-1][peak])
                r = mid - 1;
            else
                return {mid,peak};
        }
        return {mid, peak};
    }
};