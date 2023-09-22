class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mnLen = INT_MAX;
        map<int,int> mp;
        for(int i = 0;i < cards.size();i++){
            if(mp.find(cards[i]) != mp.end()) mnLen = min(mnLen,i - mp[cards[i]] + 1);
            mp[cards[i]] = i;
        }
        return mnLen == INT_MAX ? -1 : mnLen;
    }
};