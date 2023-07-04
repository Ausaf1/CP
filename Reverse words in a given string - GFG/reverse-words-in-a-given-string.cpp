//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
        string ans = "",temp = "";
        for(int i = 0;i < n;i++){
            if(S[i] == '.'){
                ans = S[i] + temp + ans;
                temp = "";
            }
            else temp += S[i];
        }
        ans = temp + ans;
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends