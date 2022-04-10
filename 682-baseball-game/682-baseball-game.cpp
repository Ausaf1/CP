class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int ans=0;
        for(auto i : ops){
            if(i=="+"){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1+temp2);
            }
            else if(i=="C")
                st.pop();
            else if(i=="D")
                st.push(st.top()*2);
            else
                st.push(stoi(i));
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};