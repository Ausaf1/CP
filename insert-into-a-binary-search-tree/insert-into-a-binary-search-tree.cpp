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
void insert(TreeNode *root,TreeNode *n,int key)
{
    TreeNode *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->val)
        {
            return;
        }
        else if (key < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (key < prev->val)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *n = new TreeNode(val);
        n->left = NULL;
        n->right = NULL;
    if(root == NULL){
         n->val = val;
         return n;
        }
        insert(root,n,val);
        return root;
    }
};