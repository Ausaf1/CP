class Solution {
public:
    
    bool helper(int a,int b,int c,int d,int e,int f,int g,int h,int i){
      set<int>s1={a,b,c,d,e,f,g,h,i};
    set<int>s2={1,2,3,4,5,6,7,8,9};
    
    if(s1==s2 && (a+b+c)==15 && (d+e+f)==15 && (g+h+i)==15 && (a+d+g)==15 && (b+e+h)==15 && (c+f+i)==15 && (a+e+i)==15 && (c+e+g)==15 && e==5 ){
        return true;
    }
    
    return false;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m < 3 && n < 3)
            return 0;
        int res = 0;
        for(int i = 0; i < m-2;i++){
            for(int j = 0;j < n-2;j++){
                if(helper(grid[i][j],grid[i][j+1],grid[i][j+2],grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]))
                    res+=1;      
            }
        }
        return res;
    }
};