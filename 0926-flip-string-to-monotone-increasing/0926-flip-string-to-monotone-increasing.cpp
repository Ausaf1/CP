class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int cf = 0,cones = 0;
        for(auto ele : s){
            if(ele == '0'){
                if(cones == 0) continue;
                else cf++;
            }
            else cones++;
            if(cf > cones) cf = cones;
        }
        return cf;
    }
};