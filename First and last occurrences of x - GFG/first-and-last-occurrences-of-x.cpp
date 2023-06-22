//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    
    int firstOccurance(int nums[], int target,int low,int high,int ans){
         if(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                return firstOccurance(nums,target,low,mid-1,ans);
            }
            else if(nums[mid]>target){
                return firstOccurance(nums,target,low,mid-1,ans);
            }
            else{
                return firstOccurance(nums,target,mid+1,high,ans);
            }
         }
        return ans;
    }
    
    int lastOccurance(int nums[], int target,int low,int high,int ans){
        if(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                return lastOccurance(nums,target,mid+1,high,ans);
            }
            else if(nums[mid]>target){
                return lastOccurance(nums,target,low,mid-1,ans);
            }
            else{
                return lastOccurance(nums,target,mid+1,high,ans);
            }
        }
        return ans;
    }

vector<int> find(int arr[], int n , int x )
{
    // code here
        int f = firstOccurance(arr,x,0,n-1,-1);
        int l = lastOccurance(arr,x,0,n-1,-1);
        return {f,l}; 
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends