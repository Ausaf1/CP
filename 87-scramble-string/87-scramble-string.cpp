class Solution {
public:
    bool helper(string s1, string s2,map<string,bool>& m)
    {
        if(s1.compare(s2) == 0)
            return true;
        if(s1.length() <= 1)
            return false; 
        string key = s1+" "+s2;
        if(m.find(key) != m.end())
            return m[key];
        int n = s1.size();
        bool flag = false;
        for(int i = 1; i < n; i++)
        { 
            bool cond1 = helper(s1.substr(0,i),s2.substr(n-i),m) && helper(s1.substr(i),s2.substr(0,n-i),m);
            bool cond2 = helper(s1.substr(0,i),s2.substr(0,i),m) && helper(s1.substr(i),s2.substr(i),m);
                                
            if(cond1 || cond2)
            {
                flag = true;
                break;
            }                    
        }
        
        return m[key] = flag; 
    }
    bool isScramble(string s1, string s2) {
        if(s1.empty() && s2.empty())
            return true;
        if(s1.size() != s2.size())
            return false;
        map<string, bool> m;
        return helper(s1,s2,m);
    }
};