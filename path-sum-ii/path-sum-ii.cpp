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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int targetSum,vector<int> &v,int sum){
        if(root == NULL){
            return;
        }
         sum+=root->val;
        v.push_back(root->val);
        if(sum == targetSum && !root->left && !root->right){
            ans.push_back(v);
        }
        helper(root->left,targetSum,v,sum);
        helper(root->right,targetSum,v,sum);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<int> v;
        helper(root,targetSum,v,0);
        return ans;
    }
};