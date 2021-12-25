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
    
    int maxIndex(vector<int> &nums,int low,int high){
        int idx = low;
        for(int i = low+1;i <= high;i++){
            if(nums[i] > nums[idx]){
                idx = i;
            }
        }
        return idx;
    }
    
    TreeNode *helper(vector<int> &nums,int low,int high){
         if(low > high){
            return NULL;
        }
        int idx = maxIndex(nums,low,high);
        TreeNode *root = new TreeNode(nums[idx]);
        root->left = helper(nums,low,idx-1);
        root->right = helper(nums,idx+1,high);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};