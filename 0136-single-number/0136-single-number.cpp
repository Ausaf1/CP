class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0,n = nums.size();
        for(int i = 0;i < n;i++) xor1 ^= nums[i];
        return xor1;
    }
};