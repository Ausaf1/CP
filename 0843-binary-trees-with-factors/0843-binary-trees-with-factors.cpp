class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    ll f(int i,vector<int> &arr,vector<ll> &dp,unordered_map<int,int> &mp){
        if(dp[i] != -1) return dp[i];
        ll res = 1,k = 2,x = arr[i];
        while(k*k<=x)
        {
            if(x%k==0)
            {
                ll j=x/k;
                if(mp.find(k)!=mp.end() && mp.find(j)!=mp.end())
                {
                    ll curr=f(mp[k],arr,dp,mp)*f(mp[j],arr,dp,mp);
                    if(k!=j)
                        curr*=2;
                    res=(res+curr)%mod;
                }
            }
            k++;
        }
        return dp[i]=res;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0;i < n;i++) mp[arr[i]] = i;
        vector<ll> dp(n,-1);
        ll res = 0;
        for(int i = 0;i < n;i++){
            res = (res + f(i,arr,dp,mp)) % mod;
        }
        return res;
    }
};