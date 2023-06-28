class Solution {
private:
    long long func(vector<int> &piles,int mid){
        long long t = 0;
        for(auto i : piles) t += ceil((double)i/(double)mid);
        return t;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(),maxx = 0;
        for(auto i : piles) maxx = max(maxx,i);
        int low = 1,high = maxx;
        while(low <= high){
            int mid = (low + high) >> 1;
            long long time = func(piles,mid);
            if(time <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};