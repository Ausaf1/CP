class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0,totalCost = 0,currGas = 0,starting = 0;
        for(int i = 0;i < n;i++){
            totalCost += cost[i],totalGas += gas[i];
            currGas += gas[i] - cost[i];
            if(currGas < 0){
                starting = i + 1;
                currGas = 0; 
            }
        }
        return totalGas < totalCost ? - 1 : starting;
    }
};