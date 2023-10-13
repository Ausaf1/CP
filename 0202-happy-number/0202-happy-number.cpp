class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(1){
            if(n == 1) return true;
            if(st.find(n) != st.end()) return false;
            st.insert(n);
            int t = 0;
            while(n){
                int rem = n % 10;
                t += pow(rem,2);
                n /= 10;
            }
            n = t;
        }   
        return false;
    }
};