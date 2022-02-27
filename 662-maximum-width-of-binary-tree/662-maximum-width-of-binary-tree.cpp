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
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int res = INT_MIN;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            auto node = q.front();
            int leftmost = node.first;
            int rightmost = INT_MIN;
            int size = q.size();
            for(int i = 0;i < size;i++){
                auto node = q.front();
                q.pop();
                TreeNode *n = node.second;
                int curr = node.first;
                rightmost = max(rightmost,node.first);
                if(n->left)
                    q.push({(ll)2*curr + 1,n->left});
                if(n->right)
                    q.push({(ll)2*curr + 2,n->right});
            }
            res = max(res,rightmost-leftmost+1);
        }
        return res;
    }
};