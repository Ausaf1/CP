class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(auto c : s){
            if(c == '#' & !s1.empty())
                s1.pop();
            else if(c == '#' && s1.empty())
                continue;
            else
                s1.push(c);
        }
        for(auto c : t){
            if(c == '#' & !s2.empty())
                s2.pop();
            else if(c == '#' && s2.empty())
                continue;
            else
                s2.push(c);
        }
        return s1 == s2;
    }
};