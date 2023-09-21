class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1) return s;
        bool flag = false;
        int i = 0;
        vector<string> ans(numRows);
        for(char ch : s){
            ans[i] += ch;
            if(i == 0 || i == numRows - 1) flag = !flag;
            if(flag) i++;
            else i--;
        }
        string zigzag = "";
        for(auto c : ans) zigzag += c;
        return zigzag;
    }
};