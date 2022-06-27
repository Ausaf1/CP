class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1){
            if(n == 1)
                return true;
            else{
                if(s.find(n) != s.end())
                    return false;
                else
                    s.insert(n);
                int t = 0;
                while(n){
                    int a = n%10;
                    t += a*a;
                    n = n/10;
                }
                n = t;
            }
        }
        return false;
    }
};