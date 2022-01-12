class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int ans = 0;
        for(auto i : nums)
            s.insert(i);
        for(auto i : nums){
            if(s.find(i+1)!=s.end()){
                continue;
            }
            int len = 0 , data = i;
            while(s.find(data)!=s.end()){
                len++;
                data--;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};