//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
     int n = bloomDay.size();
	long long mi = M * K;
	if(mi > n) return -1;
	int ans = -1;
	int mn = 1e9,mx = -1e9;
	for(int i = 0;i < n;i++) mn = min(mn,bloomDay[i]),mx = max(mx,bloomDay[i]);
	int low = mn,high = mx;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(possible(mid,M,K,bloomDay,n)){
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends