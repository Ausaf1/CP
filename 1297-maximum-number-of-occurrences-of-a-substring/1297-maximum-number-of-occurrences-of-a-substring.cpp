class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> mp1;
        unordered_map<char,int> mp2;
        int distinct = 0,i = 0,j = 0;
        int count = 0;
        while(j < s.size()){
            if(mp2[s[j]] == 0) distinct++;
            mp2[s[j]]++;
            while(j-i+1 > maxSize || distinct > maxLetters){
                mp2[s[i]]--;
                if(mp2[s[i]] == 0) distinct--;
                i++;
            }
            while(j-i+1 >= minSize && distinct <= maxLetters){
                mp1[s.substr(i,j-i+1)]++;
                mp2[s[i]]--;
                if(mp2[s[i]] == 0) distinct--;
                i++;
            }
            j++;
        }
        for(auto it : mp1) count = max(count,it.second);
        return count;
    }
};