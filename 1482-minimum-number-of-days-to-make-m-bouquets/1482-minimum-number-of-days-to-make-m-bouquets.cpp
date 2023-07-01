class Solution {
private:
    bool possible(int mid,int m,int k,vector<int> &arr,int n){
	int cnt = 0;
	long long p = 0;
	for(int i = 0;i < n;i++){
		if(arr[i] <= mid) cnt++;
		else{
			p += cnt/k;
			cnt = 0;
		}
	}
	p += cnt/k;
	if(p >= m) return true;
	return false;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
	long long mi = (long long)m * k;
	if(mi > n) return -1;
	int ans = -1;
	int mn = 1e9,mx = -1e9;
	for(int i = 0;i < n;i++) mn = min(mn,bloomDay[i]),mx = max(mx,bloomDay[i]);
	int low = mn,high = mx;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(possible(mid,m,k,bloomDay,n)){
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
    }
};