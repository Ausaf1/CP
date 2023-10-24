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
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxInEach;
        if(!root) return maxInEach;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curr_size = q.size();
            int mx = INT_MIN;
            for(int i = 0;i < curr_size;i++){
                TreeNode* node = q.front();
                q.pop();
                mx = max(mx,node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            maxInEach.push_back(mx);
        }
        return maxInEach;
    }
};