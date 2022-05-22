class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(),ans = 0;
        int l ,r;
        for(int i = 0;i < n;i++){
            l = r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r])
                    ans++;
                else
                    break;
                l--;
                r++;
            }
            if(i == 0)
                continue;
            l = i-1,r = i;
             while(l >= 0 && r < n){
                if(s[l] == s[r])
                    ans++;
                else
                    break;
                l--;
                r++;
            }
        }
        return ans;
    }
};