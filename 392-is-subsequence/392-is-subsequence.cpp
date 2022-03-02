class Solution {
public:
    bool isSubsequence(string s, string t) {
         int j = 0;
        for(auto i : t){
            if(s[j] == i){
                j++;
            }
        }
        return j == s.size();
    }
};