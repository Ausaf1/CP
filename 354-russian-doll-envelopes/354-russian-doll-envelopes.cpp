class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> lis;
        for(int i = 0;i < envelopes.size();i++){
            int h = envelopes[i][1];
            auto index = lower_bound(lis.begin(),lis.end(),h) - lis.begin();
            if(index == lis.size())
                lis.push_back(h);
            else
                lis[index] = h;
        }
        return lis.size();
    }
};