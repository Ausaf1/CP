//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    unordered_map<char,char> mp,mp1;
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        
        if(str1.length() != str2.length()) return false;
        int n = str1.length();
        for(int i = 0;i < n;i++){
            if(mp[str2[i]] > 0 && str1[i] != mp[str2[i]]) return false;
            if(mp1[str1[i]] > 0 && str2[i] != mp1[str1[i]]) return false;
            mp[str2[i]] = str1[i];
            mp1[str1[i]] = str2[i];
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends