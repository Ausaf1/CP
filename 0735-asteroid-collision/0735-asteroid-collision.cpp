class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i = 0;i < n;i++){
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int mag = st.top() + asteroids[i];
                if(mag < 0) st.pop();
                else if(mag > 0) asteroids[i] = 0;
                else{
                    st.pop();
                    asteroids[i] = 0;
                }
            }
            if(asteroids[i]) st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};