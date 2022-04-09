class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto i : nums)
            m[i]++;
        priority_queue<pair<int,int>> q;
        for(auto val: m){
        q.push({val.second, val.first});
        }
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};