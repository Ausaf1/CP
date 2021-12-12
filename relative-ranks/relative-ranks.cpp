class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> q;
        int n = score.size();
        vector<string> ans(n,"");
        for(int i = 0;i<n;i++){
            q.push({score[i],i});
        }
        for(int i = 0; i < n;i++){
            if(i==0){
                ans[q.top().second] = "Gold Medal";
            }
            else if(i==1){
                ans[q.top().second] = "Silver Medal";
            }
            else if(i==2){
                ans[q.top().second] = "Bronze Medal";
            }
            else{
                ans[q.top().second] = to_string(i+1);
            }
            q.pop();
        }
        return ans;
    }
};