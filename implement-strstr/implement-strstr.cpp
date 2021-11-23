class Solution {
public:
    int strStr(string haystack, string needle) {
      if(needle == ""){
          return 0;
      }            
        int m = haystack.size();
        int n = needle.size();
        for(int i = 0;i <=m-n; i++){
            int j = 0;
            while(j < n){
                if(haystack[i+j] != needle[j]){
                    break;
                }
                if(j == n-1){
                    return i;
                }
                j++;
            }
        }
        return -1;
    }
};