class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0,j = n-1;
        int count = 0;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                count++;
                i++;
            }
            if(count > 1)
                break;
        }
        i = 0,j = n-1;
        int count2 =  0;
        while(i < j){
             if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                count2++;
                j--;
            }
            if(count2 > 1)
                break;
        }
        if((count == 1 || count2 == 1) || (count == 0 || count2 == 0))
            return true;
        return false;
    }
};