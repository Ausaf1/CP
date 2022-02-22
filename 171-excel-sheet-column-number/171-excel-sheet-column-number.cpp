class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int res = 0;
        for(int i = 0;i < n;i++){
            res*=26;
            res += (columnTitle[i] - 'A') + 1;
        }
        return res;
    }
};