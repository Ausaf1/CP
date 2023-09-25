class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int one = 0;
        for(auto it: nums) if(it == 1) one++;
        int leftZeroes = 0,rightOnes = one;
        ans.push_back(0);
        int mx = leftZeroes + rightOnes;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0) leftZeroes++;
            else rightOnes--;
            int curr = leftZeroes + rightOnes;
            if(curr > mx){
                ans.clear();
                mx = leftZeroes + rightOnes;
                ans.push_back(i+1);
            }
            else if(curr == mx){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};