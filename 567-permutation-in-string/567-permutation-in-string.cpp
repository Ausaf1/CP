class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       map<char,int> m;
       for(auto i : s1)
           m[i]++;
        int c = m.size(),i = 0,j = 0;
        int window = s1.size();
        while(j < s2.size()){
            if(m.find(s2[j]) != m.end()){
                m[s2[j]]--;
                if(m[s2[j]] == 0)
                    c--;
            }
            if(j-i+1 < window)
                j++;
            else if(j-i+1 == window){
                if(c == 0)
                    return true;
                if(m.find(s2[i]) != m.end()){
                    m[s2[i]]++;
                    if(m[s2[i]] == 1)
                        c++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};