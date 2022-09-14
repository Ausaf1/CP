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
    int res = 0;
    unordered_map<int,int> mp;
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        mp[root->val]++;
        if(!root->left && !root->right){
            int t = 0;
            for(int i = 0;i <= 9;i++){
                if(mp[i] & 1)
                    t++;
            }
            if(t <= 1)
                res++;
        }
        helper(root->left);
        helper(root->right);
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return res;
    }
};