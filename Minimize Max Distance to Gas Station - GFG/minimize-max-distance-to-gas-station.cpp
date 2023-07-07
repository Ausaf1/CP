//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int noOfGasStations(double mid,vector<int> &stations,int n){
        int g = 0;
        for(int i = 0;i < n-1;i++){
            g += ceil((stations[i+1] - stations[i])/mid) - 1;
        }
        return g;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
      // Code here
      int n = stations.size();
      double low = 0.0,high = stations[n-1] - stations[0],ans = 0.0;
      while(low < high - 1e-6){
          double mid = (low + high)/2.0;
          int x = noOfGasStations(mid,stations,n);
          if(x > K) low = mid;
          else high = mid,ans = mid;
      }
      return high;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends