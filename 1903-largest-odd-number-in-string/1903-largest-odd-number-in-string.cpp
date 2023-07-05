class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i;
        for(i = n-1;i >= 0;i--){
            if((num[i] - '0') & 1){
                break;
            }
        }
        num.resize(i+1);
        return num;
    }
};