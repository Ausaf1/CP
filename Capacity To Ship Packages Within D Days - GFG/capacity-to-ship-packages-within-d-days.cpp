//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    int noDays(int mid,int arr[],int N){
        int days = 1,load = 0;
        for(int i = 0;i < N;i++){
            if(load + arr[i] > mid){
                days += 1;
                load = arr[i];
            }
            else load += arr[i];
        }
        return days;
    }
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int sum = 0,mx = -1e9;
        for(int i = 0;i < N;i++) sum += arr[i],mx = max(mx,arr[i]);
        int low = mx,high = sum;
        while(low <= high){
            int mid = (low + high) >> 1;
            int ndays = noDays(mid,arr,N);
            if(ndays <= D) high = mid - 1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends