class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        while(stones.size() > 1){
            int i = stones.size() - 1;
            int x = stones[i],y = stones[i-1];
            stones.pop_back();
            stones.pop_back();
            if(x != y)
                stones.push_back(x - y);
            sort(stones.begin(),stones.end());
        }
        if(stones.size() == 0)
            return 0;
        return stones[0];
    }
};