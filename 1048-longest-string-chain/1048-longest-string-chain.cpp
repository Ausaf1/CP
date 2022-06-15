class Solution {
public:
    int longestStrChain(vector<string>& words) {
       unordered_map<string, int> dp;
        int res = 1;
        sort(words.begin(), words.end(), [](const string &l, const string &r) 
             { 
                 return l.size() < r.size(); 
             }); 
        for(string word:words){
            dp[word] = 1;
            for(int i = 0;i < word.size();i++){
                string pre = word.substr(0,i) + word.substr(i+1);
                if(dp.find(pre) != dp.end()){
                    dp[word] = max(dp[word],dp[pre] + 1);
                    res = max(res,dp[word]);
                }
            }
        }
        return res;
    }
};