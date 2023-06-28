//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    long long func(vector<int> &piles,int mid){
        long long t = 0;
        for(auto i : piles) t += ceil((double)i/(double)mid);
        return t;
    }
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int n = piles.size(),maxx = 0;
        for(auto i : piles) maxx = max(maxx,i);
        int low = 1,high = maxx;
        while(low <= high){
            int mid = (low + high) >> 1;
            long long time = func(piles,mid);
            if(time <= H) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends