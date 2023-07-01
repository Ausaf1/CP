//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool possible(int mid,vector<int> &arr,int limit,int n){
	int sum = 0;
	for(int i = 0;i < n;i++){
		sum += ceil((double)arr[i]/(double)mid);
	}
	if(sum <= limit) return true;
	return false;
}

    int smallestDivisor(vector<int>& nums, int K) {
        // Write your code here.
    int n = nums.size();
	int mx = -1e9,ans = 0;
	for(int i = 0;i < n;i++) mx = max(mx,nums[i]);
	int low = 1,high = mx;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(possible(mid,nums,K,n)){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends