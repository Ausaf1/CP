class Solution {
public:
    string convert(string s){
        stack<char> st;
        for(auto it : s){
            if(it == '#'){
                if(st.empty()) continue;
                else st.pop();
            }
            else st.push(it);
        }
        string a = "";
        while(!st.empty()){
            a += st.top();
            st.pop();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        return convert(s) == convert(t);
    }
};