class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size(),n = words[0].size();
        unordered_map<string,int> wordMap;
        vector<int> ans;
        if(m*n > s.length())
            return ans;
        for(string word : words)
            wordMap[word]++;
        for(int i = 0;i <= s.length() - m*n;i++){
            unordered_map<string,int> used;
            for(int j = i;j < i + m*n;j += n){
                string curr = s.substr(j,n);
                if(wordMap.find(curr) == wordMap.end())
                    break;
                used[curr]++;
                if(used[curr] > wordMap[curr])
                    break;
            }
            if(used == wordMap)
                ans.push_back(i);
        }
        return ans;
    }
};
