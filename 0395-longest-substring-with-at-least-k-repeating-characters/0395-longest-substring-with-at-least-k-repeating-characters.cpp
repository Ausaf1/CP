class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.length();
        if(len < k) return 0;
        if(k < 2) return len;
        unordered_map<char,int> mp;
        for(auto c : s) mp[c]++;
        int i = 0,a = 0,b = 0;
        while(i < len && mp[s[i]] >= k) i++;
        if(i == len) return i;
        a = longestSubstring(s.substr(0,i),k);
        if(i < len-1) b = longestSubstring(s.substr(i+1),k);
        return max(a,b);
    }
};