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
    
TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = preorder[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lpreS = preS + 1;
    int lInE = rootIndex - 1;
    int lpreE = lInE - lInS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    TreeNode *root = new TreeNode(rootData);
    root->left = buildTreeHelper(inorder, preorder, lInS, lInE, lpreS, lpreE);
    root->right = buildTreeHelper(inorder, preorder, rInS, rInE, rpreS, rpreE);
    return root;
}
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
    }
};