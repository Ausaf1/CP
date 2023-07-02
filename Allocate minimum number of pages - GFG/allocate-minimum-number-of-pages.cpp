//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    int func(int mid,int arr[],int n){
        int noStudents = 1;
        long long pages = 0;
        for(int i = 0;i < n;i++){
            if(pages + arr[i] <= mid) pages += arr[i];
            else{
                pages = arr[i];
                noStudents++;
            }
        }
        return noStudents;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N < M) return -1;
        int low = *max_element(A,A+N);
        int high = accumulate(A,A+N,0);
        while(low <= high){
            int mid = (low + high) >> 1;
            int st = func(mid,A,N);
            if(st > M) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends