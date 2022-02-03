class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int n = 1;
        while(2*n <= label)
            n*=2;
        vector<int> ans;
        while(label > 0){
            ans.push_back(label);
            label = n/2 - label/2 + (n-1);
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};