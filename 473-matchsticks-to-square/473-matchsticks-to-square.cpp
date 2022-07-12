class Solution {
private:
    bool backtracking(vector<int>& matchsticks,vector<bool> &visited,int i,int currSum,int target,int subsets){
        if(subsets == 0)
            return true;
        if(currSum > target)
            return false;
        if(currSum == target)
            return backtracking(matchsticks,visited,0,0,target,subsets - 1);
        for(int j = i;j < matchsticks.size();j++){
            if(!visited[j]){
                visited[j] = true;
                if(backtracking(matchsticks,visited,j+1,matchsticks[j] + currSum,target,subsets))
                    return true;
                visited[j] = false;
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum % 4 != 0)
            return false;
        int target = sum/4;
        vector<bool> visited(matchsticks.size(),false);
        return backtracking(matchsticks,visited,0,0,target,4);
    }
};