class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int n = s.length(), start = 0,end = 0,ans = 0;
        while(end < n){
            freq[s[end]]++;
            while(freq[s[end]] != 1){
                freq[s[start]]--;
                start++;
            }
            ans = max(ans,end- start + 1);
            end++;
        }
        return ans;
    }
};