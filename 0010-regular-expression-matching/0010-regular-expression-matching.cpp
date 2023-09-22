class Solution {
private:
    bool f(int i,int j,string& s,string& p,vector<vector<int>> &dp){
        if(i >= s.length() && j >= p.length()) return true;
        if(j >= p.length()) return false;
        if(dp[i][j]) return dp[i][j];
        bool match = (i < s.length()) && ((s[i] == p[j]) || (p[j] == '.'));
        if(j + 1 < p.length() && p[j+1] == '*') return dp[i][j] = (f(i,j+2,s,p,dp) || (match && f(i+1,j,s,p,dp)));
        if(match) return dp[i][j] =  f(i + 1,j + 1,s,p,dp);
        else return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 2,vector<int>(p.length() + 2,false));
        if(f(0,0,s,p,dp)) return true;
        return false;
    }
};