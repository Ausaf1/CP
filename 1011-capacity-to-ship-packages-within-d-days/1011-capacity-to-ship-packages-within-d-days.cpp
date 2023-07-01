class Solution {
private:
    int numDays(int mid,vector<int> &weights,int n){
        int sum = 0,days = 1;
        for(int i = 0;i < n;i++){
            if(sum + weights[i] > mid){
                days++;
                sum = weights[i];
            }
            else{
                sum += weights[i];
            }
        }
        return days;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size();
        int sum = 0,mx = -1e9;
        for(int i = 0;i < N;i++) sum += weights[i],mx = max(mx,weights[i]);
        int low = mx,high = sum;
        while(low <= high){
            int mid = (low + high) >> 1;
            int ndays = numDays(mid,weights,N);
            if(ndays <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};