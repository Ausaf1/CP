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
   int maxsum = 0;
int maxPathSum1(TreeNode *root){
     if(root==NULL)
        return 0;
    
   int a = max(maxPathSum1(root->left),0);
   int b = max(maxPathSum1(root->right),0);
   maxsum = max(maxsum,a+b+root->val); 
   return root->val+max(a,b);
}

int maxPathSum(TreeNode* root) {

    maxsum = root->val;
   int h = maxPathSum1(root);
    return maxsum;
}
};