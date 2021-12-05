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
    int ans = 0;
    void dfs(TreeNode* root, unordered_map<int,int> &m, int sum,int targetSum){
        if(root == NULL){
            return;
        }
        sum+=root->val;
        ans+=m[sum-targetSum];
        m[sum]++;
        dfs(root->left,m,sum,targetSum);
        dfs(root->right,m,sum,targetSum);
        m[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        unordered_map<int,int> m{{0,1}};
        dfs(root,m,0,targetSum);
        return ans;
    }
};