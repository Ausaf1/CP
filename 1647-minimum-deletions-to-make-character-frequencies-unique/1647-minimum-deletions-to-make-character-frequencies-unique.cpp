class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        unordered_map<char,int> m;
        for(auto i : s)
            m[i]++;
        set<int> st;
        int ans = 0;
        for(auto [i,j] : m){
            while(st.find(j) != st.end()){
                j--;
                ans++;
            }
            if(j > 0)
               st.insert(j); 
        }
        return ans;
    }
};