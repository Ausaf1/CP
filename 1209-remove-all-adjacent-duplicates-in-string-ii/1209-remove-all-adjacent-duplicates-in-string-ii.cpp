class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        if(n < k)
            return s;
        stack<pair<char,int>> st;
        for(int i = 0;i < n;i++){
            if(st.empty() || st.top().first != s[i])
                st.push({s[i],1});
            else{
                auto p = st.top();
                st.pop();
                st.push({s[i],p.second + 1});
            }
            if(st.top().second == k)
                st.pop();
        }
        string res = "";
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            while(cur.second--){
                res += cur.first;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};