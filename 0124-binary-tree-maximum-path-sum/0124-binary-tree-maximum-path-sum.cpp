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
    int maxPath(TreeNode* root,int &mx){
        if(root == NULL) return 0;
        int leftSum = max(0,maxPath(root->left,mx));
        int rightSum = max(0,maxPath(root->right,mx));
        mx = max(leftSum + rightSum + root->val,mx);
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int mx = root->val;
        int a = maxPath(root,mx);
        return mx;
    }
};