//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int m = 1e9 + 7;
    int findWays(int idx,vector<int> &dp){
        if(idx == 0 || idx == 1) return 1;
        if(dp[idx] != -1) return dp[idx];
        int step1 = findWays(idx - 1,dp);
        int step2 = findWays(idx - 2,dp);
        return dp[idx] = (step1 + step2) % m;
    }
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
     vector<int> dp(n + 1,-1);
    return findWays(n,dp) % m;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends