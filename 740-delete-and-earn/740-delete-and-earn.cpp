class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int include = 0,exclude = 0;
        vector<int> freq(10001,0);
        for(int it:nums)
            freq[it]++;
        for(int i = 0;i < 10001;i++){
            int inc = exclude + freq[i]*i;
            int exc = max(include,exclude);
            include = inc;
            exclude = exc;
        }
        return max(include,exclude);
    }
};