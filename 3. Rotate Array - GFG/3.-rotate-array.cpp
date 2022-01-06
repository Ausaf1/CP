// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    int gcd(int a, int b)
   {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
   }

    void rotateArr(int arr[], int d, int n){
        // code here
        d = d%n;
        int g_c_d = gcd(d,n);
        for(int i = 0;i < g_c_d;i++){
            int t = arr[i];
            int j = i;
            while(1){
                int a = j+d;
                if(a>=n){
                    a-=n;
                }
                if(a==i)
                break;
                arr[j] = arr[a];
                j = a;
            }
            arr[j] = t;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends