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
        vector<int> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0){
            int n = q.size();
            int maximum = INT_MIN;
            for(int i = 0; i < n; i++){
                root = q.front();
                q.pop();
                if(root->val > maximum)
                    maximum = root->val;
                
                if(root->left != NULL)
                    q.push(root->left);
                if(root->right != NULL)
                    q.push(root->right);
            }
            res.push_back(maximum);
        }
        return res;
    }
};