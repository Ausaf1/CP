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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int lsum = 0,rsum = 0,sum = 0;
        if(root == NULL){
            return 0;
        }
        if(root->val>=low && root->val<=high){
            sum+=root->val;
            lsum = rangeSumBST(root->left,low,high);
            rsum = rangeSumBST(root->right,low,high);
        }
        else if(root->val < low || !root->left ){
            lsum = 0;
            rsum = rangeSumBST(root->right,low,high);
        }
        else if(root->val > high || !root->right){
            rsum = 0;
            lsum = rangeSumBST(root->left,low,high);
        }
        sum+=lsum + rsum;
        return sum;
    }
};