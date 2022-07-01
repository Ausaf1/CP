class Solution {
public:
    vector<vector<int>> ans;
    void allCombinations(int n,int k,int start,vector<int> &s){
        if(s.size() == k){
            ans.push_back(s);
            return;
        }
        for(int i = start;i < n;i++){
            s.push_back(i+1);
            allCombinations(n,k,i+1,s);
            s.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> s;
        allCombinations(n,k,0,s);
        return ans;
    }
};