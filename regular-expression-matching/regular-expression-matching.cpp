class Solution {
public:
    
        
    int dfs(int i, int j, string& s , string& p, vector<vector<int>>& dp){
        if(i>=s.length() and j>=p.length())
            return true;
        if(j>=p.length())
            return false;
        if(dp[i][j])
            return dp[i][j];
        
        bool match =  (i<s.length())  and ((s[i]==p[j]) or (p[j]=='.'));
            
            if(j+1<p.length() and p[j+1]=='*')
                return dp[i][j]=( dfs(i,j+2,s ,p,dp) or(match and dfs(i+1,j,s,p,dp)) );
        
        if(match)
            return dp[i][j]= dfs(i+1,j+1,s,p,dp);
        
        else 
            return dp[i][j]=false;
                
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+2,vector<int>(p.length()+2,false));
         if(dfs(0,0,s,p,dp))
             return true;
        return false;
    }
};