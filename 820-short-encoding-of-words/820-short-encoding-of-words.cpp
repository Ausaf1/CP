class Solution {
public:
    
    static bool compare(string &f,string &s){
        return f.size() > s.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans = 0;
        sort(words.begin(),words.end(),compare);
        for(auto word : words)
            mp[word]++;
        for(int i = 0;i < words.size();i++){
            int k = words[i].size();
            if(mp[words[i]] > 0)
                ans += k+1;
            for(int j = k - 1;j >= 0;j--){
                string s = words[i].substr(j,k-j);
                mp[s] = 0;
            }
        }
        return ans;
    }
};