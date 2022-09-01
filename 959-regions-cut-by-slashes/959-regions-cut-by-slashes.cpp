class Solution {
public:
    vector<string> g;
    int h,w;
    vector<vector<vector<bool>>> visited;
    
    bool valid(int row,int col){
        return row >= 0 && row < h && col >= 0 && col < w;
    }
    void dfs(int row,int col,int type){
        if(!valid(row,col) || visited[row][col][type])
            return;
        visited[row][col][type] = true;
        if(type == 0)
            dfs(row-1,col,2);
        else if(type == 1)
            dfs(row,col+1,3);
        else if(type == 2)
            dfs(row+1,col,0);
        else if(type == 3)
            dfs(row,col-1,1);
        else
            assert(false);
        if(g[row][col] != '/')
            dfs(row,col,type^1);
        if(g[row][col] != '\\')
            dfs(row,col,type^3);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        g = grid;
        int res = 0;
        h = g.size(),w= g[0].size();
        visited.clear();
        visited.resize(h,vector<vector<bool>>(w,vector<bool>(4)));
        for(int row = 0;row < h;row++){
            for(int col = 0;col < w;col++){
                for(int t = 0;t < 4;t++){
                    if(!visited[row][col][t]){
                    dfs(row,col,t);
                    res++;
                    }
                }
            }
        }
        return res;
    }
};