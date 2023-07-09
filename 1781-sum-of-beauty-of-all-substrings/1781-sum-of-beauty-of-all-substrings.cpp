class Solution {
public:
    int beautySum(string s) {
        int res = 0,n = s.size();
        for(int i = 0;i < n;i++){
            int cnt[26] = {},mxf = INT_MIN,mnf = INT_MAX;
            for(int j = i;j < n;j++){
                int idx = s[j] - 'a';
                cnt[idx]++;
                mxf = max(mxf,cnt[idx]);
                mnf = cnt[idx];
                for(int k = 0;k < 26;k++){
                    if(cnt[k] >= 1) mnf = min(mnf,cnt[k]);
                }
                res += (mxf - mnf);
            }
        }
        return res;
    }
};