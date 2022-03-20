class Solution {
public:
    int helper(vector<int>& tops, vector<int>& bottoms){
        int n = tops.size();
        int ans = INT_MIN;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++) {
            mp1[tops[i]]++;
            if(tops[i]!=bottoms[i])
                mp2[bottoms[i]]++;
        }
        for(int i = 1;i <= 6;i++){
            int a = mp1[i] + mp2[i];
            if(a == n){
                ans = mp2[i];
                break;
            }
        }
        return ans;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(helper(tops,bottoms),helper(bottoms,tops));
        return ans == INT_MIN ? -1 : ans;
    }
};