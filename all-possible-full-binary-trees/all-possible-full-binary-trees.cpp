/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> helper(vector<vector<TreeNode*>> &dp,int n){
         if(n==1)
            return {new TreeNode(0)};
        if(dp[n].size()) 
            return dp[n];
        vector<TreeNode*>ans;
        for(int i = 1;i<n;i+=2){
            vector<TreeNode*>l = helper(dp,i);
            vector<TreeNode*>r = helper(dp,n-i-1);
          for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    TreeNode*root=new TreeNode(0);
                    root->left=l[j];
                    root->right=r[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
       vector<vector<TreeNode*>> dp(n+1);
        return helper(dp,n);
    }
};