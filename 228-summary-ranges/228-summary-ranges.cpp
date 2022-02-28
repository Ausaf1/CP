class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(!nums.size())
            return ans;
        int a = nums[0],b = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(b+1 == nums[i])
                b = nums[i];
            else
                a == b ? ans.push_back(to_string(a)) : ans.push_back(to_string(a) + "->" + to_string(b)),a = b = nums[i];
        }
    a == b ? ans.push_back(to_string(a)) : ans.push_back(to_string(a) + "->" + to_string(b));  
        return ans;
    }
};