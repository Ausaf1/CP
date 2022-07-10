class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int lastStepCost = 0;
        int currentStepCost = cost[0];
        int tempCost = 0;
        for (int i = 1; i < cost.size(); i++)
        {
            tempCost = currentStepCost;
            currentStepCost = cost[i] +  min(currentStepCost, lastStepCost);
            lastStepCost = tempCost;
        }
        return min(lastStepCost, currentStepCost);
    }
};