class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> counts;
        for(auto t : tasks) counts[t]++;
        priority_queue<int> pq;
        int ans = 0;
        for(auto c : counts) pq.push(c.second);
        while(!pq.empty()){
            vector<int> temp;
            int time = 0;
            for(int i = 0;i <= n;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t : temp){
                if(t) pq.push(t);
            }
            ans += pq.empty() ? time : n+1;
        }
        return ans;
    }
};