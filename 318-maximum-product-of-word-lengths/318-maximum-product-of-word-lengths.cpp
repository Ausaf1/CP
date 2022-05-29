class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<int> m(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < words[i].length();j++)
                m[i] |= (1 << (words[i][j] - 'a'));
        }
        for(int i = 0;i < n;i++){
            int n1 = words[i].length();
            for(int j = i + 1;j < n;j++){
                int n2 = words[j].length();
                if((m[i] & m[j]) == 0)
                    ans = max(ans,n1*n2);
            }
        }
        return ans;
    }
};