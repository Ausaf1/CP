class Solution {
public:
 int preq[15];
    int N, K;
    int dp[1<<15];

    int getMin(int vis) {
        if(vis == (1<<N) - 1)
            return 0;
        if (dp[vis] != -1)
            return dp[vis];
        int can = 0;
        for(int c = 0; c < N; ++c)
            if ((vis&(1<<c)) == 0 && (preq[c]&vis)==preq[c])
                can |= (1<<c);
        int ans = 15;
        for (int submask = can; submask > 0; submask = (submask-1)&can) 
            if (__builtin_popcount(submask) <= K) 
                ans = min(ans, getMin(vis|submask) + 1);
        return dp[vis] = ans;
    }
    
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
          memset(dp,-1,sizeof(dp));
        N = n, K = k;
        for(auto& e : relations)
            preq[e[1]-1] |= (1<<(e[0]-1));
        return getMin(0);
    }
};