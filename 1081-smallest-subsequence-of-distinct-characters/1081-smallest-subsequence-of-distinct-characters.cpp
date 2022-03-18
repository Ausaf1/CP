class Solution {
public:
    string smallestSubsequence(string s) {
         vector<int> count( 26,0),visited(26,0);
        string ans =  "";
        int n = s.length();
        for(int i = 0;i < n;i++){
            count[s[i] - 'a']++;
        }
        for(int i = 0;i < n;i++){
            count[s[i] - 'a']--;
            if(!visited[s[i] - 'a']){
                while(ans.size() > 0 && ans.back() > s[i] && count[ans.back() - 'a'] > 0){
                    visited[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                ans += s[i];
                visited[s[i] - 'a'] = 1;
            }
        }
        return ans;
    }
};