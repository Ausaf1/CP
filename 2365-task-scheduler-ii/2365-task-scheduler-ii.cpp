class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> mp;
        long long ans = 0;
        long long n = tasks.size();
        for(long long i = 0;i < n;i++){
            if(mp[tasks[i]]){
                if(ans - mp[tasks[i]] <= space) ans = mp[tasks[i]] + space + 1;
                else ans++;
            }
            else{
                ans++;
            }
            mp[tasks[i]] = ans;
        }
        return ans;
    }
};