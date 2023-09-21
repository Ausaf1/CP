class Solution {
private:
    void helper(int left,int right,string &s,int &mxLen){
        while(left >= 0 && right <= s.size() && s[left] == s[right]){
            if(right - left + 1 > mxLen){
                mxLen = right - left + 1;
                l = left;
                r = right;
            }
            left--;
            right++;
        }
    }
public:
    int l = 0,r = 0;
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s.substr(0,1);
        if(n == 2 && s[0] == s[1]) return s;
        int mxLen = 1;
        for(int i = 1;i < n-1;i++) helper(i-1,i+1,s,mxLen);
        for(int i = 0;i < n-1;i++) helper(i,i+1,s,mxLen);
        return s.substr(l,r-l+1);
    }
};