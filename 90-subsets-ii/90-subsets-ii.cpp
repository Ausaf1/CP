class Solution {
public:
    void helper(int i,vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans){
    ans.push_back(ds);
    for(int j = i;j < arr.size();j++){
        if(j != i && arr[j] == arr[j-1])
            continue;
        ds.push_back(arr[j]);
        helper(j+1,arr,ds,ans);
        ds.pop_back();
    }
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
       sort(nums.begin(),nums.end());
       vector<int> ds;
       helper(0,nums,ds,ans);
       return ans;
    }
};