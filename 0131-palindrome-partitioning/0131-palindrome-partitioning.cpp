class Solution {
public:
    bool isPalindrome(string str, int startIndex, int lastIndex){
        while(startIndex <= lastIndex){
            if(str[startIndex] != str[lastIndex])
                return false;
            startIndex++;
            lastIndex--;
        }
        return true;
    }
    void backtrack(int idx,vector<string> &ds,vector<vector<string>> &res,string s){
        if(idx == s.length()){
            res.push_back(ds);
            return;
        }
        for(int i = idx;i < s.length();i++){
            if(isPalindrome(s,idx,i)){
                ds.push_back(s.substr(idx,i - idx + 1));
                backtrack(i + 1,ds,res,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        backtrack(0,ds,res,s);
        return res;
    }
};