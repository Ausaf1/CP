class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str = "";
        while(columnNumber--){
            int r = columnNumber%26;
            str += 'A' + r;
            columnNumber/=26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};