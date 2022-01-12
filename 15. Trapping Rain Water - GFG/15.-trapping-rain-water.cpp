// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        stack<int> st;
        long long ans = 0;
        for(int i = 0;i < n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
          int pop_height = arr[st.top()];
            st.pop();
            if (st.empty())
                break;
            int distance = i - st.top() - 1;
            int min_height = min(arr[st.top()],arr[i]) - pop_height;
            ans += distance * min_height;
        }
        st.push(i);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends