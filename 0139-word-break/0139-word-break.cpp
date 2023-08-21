class Solution {
private:
    bool f(int i,string s,vector<string> &wordDict,vector<int> &dp){
        if(i < 0) return 1;
        if(dp[i] != -1) return dp[i];
        for(string& w : wordDict){
            int size = w.size();
            if(i - size + 1 < 0) continue;
            if(s.rfind(w,i - size + 1) == i - size + 1 && f(i - size,s,wordDict,dp)) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(n-1,s,wordDict,dp);
    }
};