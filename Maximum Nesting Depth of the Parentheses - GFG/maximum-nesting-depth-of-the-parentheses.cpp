//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int n = s.length(),cnt = 0,mx = INT_MIN;
        for(int i = 0;i < n;i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') {
                mx = max(mx,cnt);
                cnt--;
            }
            else mx = max(mx,cnt);
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends