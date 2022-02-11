class Solution {
    
private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
         bool res = true;
        if(grid1[i][j] == 0)
            res = false;
        grid2[i][j] = 3;
        if(i-1 >= 0 && grid2[i-1][j] == 1)
            if(!dfs(grid1,grid2,i-1,j))
                res = false;
        if(j-1 >= 0 && grid2[i][j-1] == 1)
            if(!dfs(grid1,grid2,i,j-1))
                res = false;
        if(i+1 < grid2.size() && grid2[i+1][j] == 1)
            if(!dfs(grid1,grid2,i+1,j))
                res = false;
        if(j+1 < grid2[0].size() && grid2[i][j+1] == 1)
            if(!dfs(grid1,grid2,i,j+1))
                res = false;
        return res;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int i = 0;i < grid2.size();i++){
            for(int j = 0;j < grid2[i].size();j++){
                if(grid2[i][j] == 1)
                    if(dfs(grid1,grid2,i,j))
                        count++;
            }
        }
        return count;
    }
};