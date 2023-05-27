class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        int n = s.length();
        map<char,int> mp;
        for(auto c : s) mp[c]++;
        for(int i = 0;i < n;i++){
            if(mp[s[i]] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};