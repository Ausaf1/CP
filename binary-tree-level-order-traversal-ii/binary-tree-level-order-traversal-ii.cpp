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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            vector<int> v;
            int n = q.size();
            for(int i = 0; i < n; i++){
            root = q.front();
            q.pop();
            if(root->left!=NULL){
                q.push(root->left);
            }
             if(root->right!=NULL){
                q.push(root->right);
            }
                v.push_back(root->val);
          }
            ans.push_back(v);
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};