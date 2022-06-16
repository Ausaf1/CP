class Solution {
public:
    string longestPalindrome(string s) {
        int greatest_len = 0;
        string subs = "";
        int l = s.length();
        for(int mid = 0;mid<l;mid++){
            for(int j = 0;mid-j>=0 && mid+j<l;j++){
                if(s[mid-j]!=s[mid+j]){
                    break;
                }
                int len = 2*j+1;
                if(len>greatest_len){
                    greatest_len = len;
                    subs = s.substr(mid-j, len);
                }
            }
        }
        for(int mid = 0; mid<l-1;mid++){
            for(int j = 1;mid-j+1>=0 && mid+j<l;j++){
                if(s[mid-j+1]!=s[mid+j]){
                    break;
                }
                int len = 2*j;
                if(len>greatest_len){
                    greatest_len = len;
                    subs = s.substr(mid-j+1, len);
             } 
        }
    }
            return subs;
    }
};