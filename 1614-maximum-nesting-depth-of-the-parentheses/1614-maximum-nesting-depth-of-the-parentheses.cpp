class Solution {
public:
    int maxDepth(string s) {
        int n = s.length(),cnt = 0,mx = INT_MIN;
        for(int i = 0;i < n;i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') {
                mx = max(mx,cnt);
                cnt--;
            }
            else mx = max(mx,cnt);
        }
        return mx;
    }
};