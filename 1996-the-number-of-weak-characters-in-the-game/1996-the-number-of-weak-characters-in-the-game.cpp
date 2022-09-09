class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),compare);
        int maxNow = INT_MIN;
        int ans = 0;
        for(auto p : properties){
            if(maxNow > p[1])
                ans++;
            else
                maxNow = p[1];
        }
        return ans;
    }
};