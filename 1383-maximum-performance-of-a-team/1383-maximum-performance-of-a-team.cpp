class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        static int mod = 1e9 + 7;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> v;
        for(int i = 0;i < n;i++)
            v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());
        long sp = 0,ans = 0;
        for(int i = 0;i < n;i++){
            int curEff = v[i].first,curSpeed = v[i].second;
            if(pq.size() == k){
                sp -= pq.top();
                pq.pop();
            }
            pq.push(curSpeed);
            sp += curSpeed;
            ans = max(ans,curEff*sp);
        }
        return ans%mod;
    }
};