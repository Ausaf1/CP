class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        deque<int> q;
        vector<int> res(n);
        for(int i = 0;i<n;i++){
            q.push_back(i);
        }
        for(int i = 0;i<n;i++){
            int j = q.front();
            res[j] = deck[i];
            q.pop_front();
            int k = q.front();
            q.pop_front();
            q.push_back(k);
        }
        return res;
    }
};