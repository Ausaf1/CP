class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.size();
       vector<bool> dp(n+1,false);
       dp[n] = true;
       for(int i = n-1;i >= 0;i--){
           for(auto word : wordDict){
               int j = word.size();
               if((i+j <= n) && s.substr(i,j) == word)
                   dp[i] = dp[i+j];
               if(dp[i] == true)
                   break;
           }
       } 
        return dp[0];
    }
};