class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = books[0][1];
        for(int i = 2;i <= n;i++){
            int height = books[i-1][1];
            int width = books[i-1][0];
            dp[i] = dp[i-1] + height;
            for(int j = i-1;j > 0 && (width + books[j-1][0] <= shelfWidth);j--){
                height = max(height,books[j-1][1]);
                width+=books[j-1][0];
                dp[i] = min(dp[i], height+dp[j-1]);
            }
        }
        return dp[n];
    }
};