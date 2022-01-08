class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int a = INT_MAX,profit = 0;
        for(int i = 0; i < n;i++){
            a = min(a,prices[i]);
            if((prices[i] - a) > 0){
                profit+=(prices[i] - a);
                a = prices[i];
            }
        }
        return profit;
    }
};