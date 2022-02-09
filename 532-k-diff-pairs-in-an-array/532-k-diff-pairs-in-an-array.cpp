class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       unordered_map<int,int> m;
        int count = 0;
        for(auto x : nums)
            m[x]++;
        for(auto i : m){
            if(k == 0){
                if(i.second > 1)
                    count++;
            }
            else{
                if(m.count(i.first - k))
                    count++;
            }
        }
        return count;
    }
};