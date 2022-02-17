class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates,int i,int sum,vector<int> a,int target){
        if(i >= candidates.size())
            return;
        if(candidates[i]+sum == target){
            a.push_back(candidates[i]);
            ans.push_back(a);
        }
        if(candidates[i]+sum < target){
            vector<int> a1 = a;
            vector<int> a2 = a;
            a2.push_back(candidates[i]);
            helper(candidates,i,sum+candidates[i],a2,target);
            helper(candidates,i+1,sum,a1,target);
        }
        else{
            helper(candidates,i+1,sum,a,target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> a;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,0,a,target);
        return ans;
    }
};