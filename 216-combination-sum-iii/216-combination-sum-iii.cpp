class Solution {
public:
    vector<vector<int>> ans;
    int sum(vector<int> &comb){
        int a = 0;
        for(int i = 0;i < comb.size();i++)
            a += comb[i];
        return a;
    }
    void helper(int k,int n,vector<int> &comb,int num){
        if(k == 0){
            if(sum(comb) == n){
                ans.push_back(comb);
            }
            return;
        }
        if(num > 9)
            return;
        comb.push_back(num);
        helper(k - 1,n,comb,num+1);
        comb.pop_back();
        helper(k,n,comb,num+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        helper(k,n,comb,1);
        return ans;
    }
};