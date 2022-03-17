class Solution {
public:
    int scoreOfParentheses(string s) {
        int d = 0,ans = 0;
        char prev = '(';
        for(auto c : s){
            if(c == '(')
                d++;
            else{
                d--;
                if(prev == '(')
                    ans += 1 << d;
            }
            prev = c;
        }
        return ans;
    }
};