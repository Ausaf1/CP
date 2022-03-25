class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> difference;
        int min = 0;
        for(int i = 0;i < costs.size();i++){
            min += costs[i][0];
            difference.push_back(costs[i][1] - costs[i][0]);
        }
        sort(difference.begin(),difference.end());
        for(int i = 0;i < costs.size()/2;i++)
            min += difference[i];
        return min;
    }
};