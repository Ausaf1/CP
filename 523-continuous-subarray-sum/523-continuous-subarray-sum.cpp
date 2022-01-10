class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>m = {{0,-1}};
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum = (sum+nums[i])%k;
            if(m.count(sum)){
                if((i - m[sum])>1)
                    return true;
            }
            else
                m[sum] = i;
        }
        return false;
    }
};