class Solution {
public:
    vector<vector<int>> v; 
    void sub(vector<int>& nums, int i, vector<int> set){
        if(i == nums.size()){
            v.push_back(set);
            return;
        }
        vector<int> v1 =set;
        vector<int> v2 =set;
        v1.push_back(nums[i]);
        sub(nums,i+1,v1);
        sub(nums,i+1,v2);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> vect;
    sub(nums,0,vect);
    return v;
 }
};