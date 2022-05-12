class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> t = nums;
        do{
            next_permutation(t.begin(),t.end());
            s.insert(t);
        }while(t != nums);
        vector<vector<int>> ans;
        for(auto i : s)
            ans.push_back(i);
        return ans;
    }
};