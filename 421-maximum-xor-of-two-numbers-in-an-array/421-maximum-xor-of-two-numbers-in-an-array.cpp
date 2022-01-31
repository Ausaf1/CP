class trieNode{
public :
    trieNode *left;
    trieNode *right;
    trieNode *head;
};
    void insert(int n,trieNode *head){
    trieNode *curr = head;
    for(int i = 31;i >= 0;i--){
        int b = (n>>i) & 1;
        if(b == 0){
            if(!curr->left)
                curr->left = new trieNode();
            curr = curr->left;
        }
        else{
            if(!curr->right)
                curr->right = new trieNode();
            curr = curr->right;
        }
    }
}
class Solution {
public:
    int maxXor(trieNode *head,vector<int> &nums,int n){
        int maxXor = INT_MIN;
        for(int i = 0;i < n;i++){
            int data = nums[i];
            trieNode *curr = head;
            int c = 0;
            for(int j = 31;j >= 0;j--){
                int a = (data >> j) & 1;
                if(a == 0){
                    if(curr->right){
                        c +=pow(2,j);
                        curr = curr->right;
                    }
                    else
                        curr = curr->left;
                }
                else{
                    if(curr->left){
                        c += pow(2,j);
                        curr = curr->left;
                    }
                    else
                        curr = curr->right;
                }
            }
            maxXor = max(c,maxXor);
        }
        return maxXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
       trieNode *head = new trieNode();
    for(int i = 0;i < nums.size();i++){
        insert(nums[i],head);
    }
        return maxXor(head,nums,nums.size());
    }
};