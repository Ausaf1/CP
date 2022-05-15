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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        while(q.size() > 1){
            auto c = q.front();
            q.pop();
            if(!c){
                q.push(NULL);
                sum = 0;
                continue;
            }
            sum += c->val;
            if(c->left)
                q.push(c->left);
            if(c->right)
                q.push(c->right);
        }
        return sum;
    }
};