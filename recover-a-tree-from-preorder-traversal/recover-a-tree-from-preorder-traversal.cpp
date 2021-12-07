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
    TreeNode* recoverFromPreorder(string traversal) {
       int size = traversal.size();
        if(size == 0){
            return NULL;
        }
        vector<pair<TreeNode*,int>> v;
        int i = 0,l=0;
        while(i<size){
            int data = 0;
            while(i<size && traversal[i]!='-'){
                data = data*10 + (traversal[i]-'0');
                i++;
            }
            TreeNode* n = new TreeNode(data);
            v.push_back(make_pair(n,l));
            l = 0;
            while(i<size && traversal[i]=='-'){
                l++;
                i++;
            }
        }
        for(int i = 1;i<v.size();i++){
           for(int j = i-1;j>=0;j--){
               if(v[i].second > v[j].second){
                   if(!v[j].first->left){
                       v[j].first->left = v[i].first;
                   }
                   else{
                       v[j].first->right = v[i].first;
                   }
                   break;
               }
           }
        }
        return v[0].first;
    }
};