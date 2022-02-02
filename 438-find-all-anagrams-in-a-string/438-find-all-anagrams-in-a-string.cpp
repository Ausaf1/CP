class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(),m=p.size();
        vector<int> h(26,0);
        vector<int> ph(26,0);
        vector<int> ans;
        if(m>n)
            return ans;
        for(auto x: p){
            h[x-'a']++;
        }
        for(int i=0;i<m;i++){
            ph[s[i]-'a']++;
        }
        for(int i=m;i<n;i++){
            if(h == ph)ans.push_back(i-m);
            ph[s[i-m]-'a']--;
            ph[s[i]-'a']++;
        }
        if(h == ph)
            ans.push_back(n-m);
        return ans;
    }
};