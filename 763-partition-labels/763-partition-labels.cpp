class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        vector<int> ans;
        int n = s.length();
        for(int i = n-1;i >= 0;i--){
            if(m.find(s[i]) == m.end())
                m[s[i]] = i;
        }
        int start = -1,maxIndex = 0;
        for(int i = 0;i < n;i++){
            maxIndex = max(maxIndex,m[s[i]]);
            if(i == maxIndex){
                ans.push_back(maxIndex - start);
                start = i;
            }
        }
        return ans;
    }
};