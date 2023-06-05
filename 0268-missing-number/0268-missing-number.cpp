class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),xor1 = 0;
        for(int i = 0;i < n;i++) xor1 ^= nums[i],xor1 ^= (i + 1);
        return xor1;
    }
};