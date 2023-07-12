class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0,j = 0,res = 0,mxfreq = 0;
        unordered_map<char,int> mp;
        for(int i = 0;i < s.size();i++){
            mp[s[i]]++;
            mxfreq = max(mxfreq,mp[s[i]]);
            if(i- j + 1 - mxfreq > k){
                mp[s[j]]--;
                j++;
            }
            res = max(res,i-j+1);
        }
        return res;
    }
};