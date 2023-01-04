class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(auto i : tasks) mp[i]++;
        int ans = 0;
        for(auto t : mp){
            if(t.second < 2) return -1;
            else if(t.second % 3 == 1) ans += (t.second - 4)/3 + 2;
            else if(t.second % 3 == 0) ans += t.second/3;
            else if(t.second % 3 == 2) ans += (t.second - 2)/3 + 1; 
        }
        return ans;
    }
};