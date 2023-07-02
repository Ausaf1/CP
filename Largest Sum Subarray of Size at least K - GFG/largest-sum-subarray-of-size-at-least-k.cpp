//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int sum = 0,last = 0,j = 0,ans = LLONG_MIN;
    for(long long int i = 0;i < k;i++) sum += a[i];
    ans = (ans > sum) ? ans : sum;
    for(long long int i = k;i < n;i++){
        sum += a[i];
        last = last + a[j++];
        ans = (ans > sum) ? ans : sum;
        if(last < 0){
            sum -= last;
            ans = (ans > sum) ? ans : sum;
            last = 0;
        }
    }
    return ans;
}