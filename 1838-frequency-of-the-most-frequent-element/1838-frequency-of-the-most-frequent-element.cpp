class Solution {
public:
    #define ll long long
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0,c = 0,res = 1;
        for(int j = 1;j < nums.size();j++){
            c += (ll)(nums[j] - nums[j-1])*(j-i);
            while(c > k){
               c -= (ll)nums[j] - nums[i];
               i++;
           }
            res = max(res, j - i + 1);
        }
        return res;
    }
};