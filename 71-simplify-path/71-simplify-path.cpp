class Solution {
public:
    string simplifyPath(string path) {
       string s,ans;
       stack<string> st;
       path.push_back('/');
        for(auto i : path){
            if(i == '/'){
                if(s.empty())
                    continue;
                if(s == ".." && !st.empty())
                    st.pop();
                else if(s!="." && s!="..")
                    st.push(s);
                s = "";
            }
            else
                s.push_back(i);
        }
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.empty())
            ans.push_back('/');
        return ans;
    }
};