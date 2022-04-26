class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long r = n-index-1,l = index,high = maxSum,low = 1,ans = 0;
        while(low <= high){
            long mid = (low + high)/2;
            long sum = mid,m = mid - 1;
            long rightSum = (r <= m) ? (m*(m+1)/2 - (m-r)*(m-r+1)/2) : (m*(m+1)/2 + (r - m));
            long leftSum = (l <= m) ? (m*(m+1)/2 - (m-l)*(m-l+1)/2) : (m*(m+1)/2 + (l - m));
            sum += leftSum + rightSum;
            if(sum <= maxSum){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};