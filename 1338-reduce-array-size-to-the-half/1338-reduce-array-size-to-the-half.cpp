class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq;
        unordered_map<int,int> mp;
        for(int i : arr)
            mp[i]++;
        for(auto i : mp)
            freq.push_back(i.second);
        sort(freq.begin(),freq.end(),greater<int>());
        int sum = 0,ans = 0;
        for(int i = 0;i < freq.size();i++){
            sum += freq[i];
            if(sum >= n/2)
                return (i+1);
        }
        return -1;
    }
};