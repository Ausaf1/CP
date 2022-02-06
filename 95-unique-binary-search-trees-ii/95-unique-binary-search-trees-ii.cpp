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
    // Time Complexity = O(catalan number)
    vector<TreeNode*> helper(int l, int r){
        if(l > r)
            return {NULL};
        vector<TreeNode*> res;
        for(int root = l;root <= r;root++){
            vector<TreeNode*> left = helper(l,root - 1);
            vector<TreeNode*> right = helper(root+1,r);
            for(auto i : left){
                for(auto j : right){
                    TreeNode * node = new TreeNode(root);
                    node->left = i;
                    node->right = j;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
     return helper(1,n);   
    }
};