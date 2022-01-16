class Solution {
public:
    int uniquePaths(int m, int n) {
        int currX=0,currY=0;
        vector <vector <int>> v(n,vector <int>(m,-1));
        return helper (currX,currY,m,n,v);
    }
    int helper (int currX, int currY, int m, int n, vector<vector<int>> &v) {
        if (currX==n-1 and currY==m-1)
            return 1;
        else if (currX>=n or currY>=m)
            return 0;
        if (v[currX][currY]!=-1) {
            return v[currX][currY];
        }
        int down = helper (currX, currY+1,m,n,v);
        int right = helper (currX+1, currY,m,n,v);
        v[currX][currY]=down+right;
        return down+right;
    }
};