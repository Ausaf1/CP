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
class BSTIterator {
public:
    stack <TreeNode*> st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left){
            root = root->left;
            st.push(root);
        }
    }
    
    int next() {
        TreeNode *root = st.top();
        st.pop();
        int res = root->val;
        if(root->right){
            root = root->right;
            st.push(root);
            while(root->left){
                st.push(root->left);
                root = root->left;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */