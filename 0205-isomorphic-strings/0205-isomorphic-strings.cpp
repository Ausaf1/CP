class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp,mp1;
        if(s.length() != t.length()) return false;
        int n = s.length();
        for(int i = 0;i < n;i++){
            if(mp[t[i]] > 0 && s[i] != mp[t[i]]) return false;
            if(mp1[s[i]] > 0 && t[i] != mp1[s[i]]) return false;
            mp[t[i]] = s[i];
            mp1[s[i]] = t[i];
        }
        return true;
    }
};