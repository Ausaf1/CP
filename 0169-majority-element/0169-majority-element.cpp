class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moor's Voting Algo
        int cnt = 0,ele;
        for(int i = 0;i < nums.size();i++){
            if(cnt == 0){
                cnt++;
                ele = nums[i];
            }
            else if(nums[i] == ele) cnt++;
            else cnt--;
        }
        return ele;
    }
};