class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size();
        int sum = 0,ans = 0;
        for(int i = 0;i < n;i++){
            if(sum + costs[i] <= coins) sum += costs[i],ans++;
        }
        return ans;
    }
};