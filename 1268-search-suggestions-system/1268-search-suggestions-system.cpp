class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int l = 0,r = products.size() - 1;
        vector<vector<string>> ans;
        for(int i = 0;i < searchWord.length();i++){
            char c = searchWord[i];
            vector<string> temp;
            while(l <= r && products[l][i] != c)
                l++;
            while(l <= r && products[r][i] != c)
                r--;
            for(int j = l;j < l + min(3,r-l+1);j++)
                temp.push_back(products[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};