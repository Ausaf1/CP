class Solution {
public:
set<vector<int>> st;
    void helper(vector<int> &arr,int start,vector<int>&temp){
        if(arr.size()==start){
            if(temp.size()>1)st.insert(temp);
            return;  
         }
         int curr=arr[start];
         int prev=temp.size()==0?-105:temp[temp.size()-1];

         if(curr>=prev){
            temp.push_back(curr);
            helper(arr,start+1,temp);
            temp.pop_back();
            helper(arr,start+1,temp);
         }
         else{ 
             helper(arr,start+1,temp);
         }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        helper(nums,0,temp);
        return vector(st.begin(),st.end());
    }
};