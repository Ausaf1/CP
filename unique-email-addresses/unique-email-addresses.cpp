class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_set<string> st;
        for(string &i : emails){
            string res;
            for(auto c : i){
                if(c == '+' || c == '@')
                    break;
                if(c == '.')
                    continue;
                res += c;
            }
            res += i.substr(i.find('@'));
            st.insert(res);
        }
        return st.size();
    }
};