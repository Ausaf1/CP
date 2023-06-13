//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        // 15 0
        // 13 1
        // 15 2
        // 7 3
        // 8 4
        // 15 5
        // 25 6
        // 48 7
        unordered_map<int,int> mp;
        int sum = 0,maxLen = 0;
        for(int i = 0;i < n;i++){
            sum += A[i];
            if(sum == 0) maxLen = max(maxLen,i + 1);
            if(mp.find(sum) != mp.end()){
                maxLen = max(maxLen,i - mp[sum]);
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends