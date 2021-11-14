class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {  
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> ans;
        int a = nums1.size();
        int b = nums2.size();
        for(int i = 0;i<a;i++){
         m1[nums1[i]]++;   
        }
        for(int i = 0;i<b;i++){
         m2[nums2[i]]++;   
        }
        if(a>=b){
        unordered_map<int,int>::iterator it;
        for(it=m1.begin();it!=m2.end();it++){
            if(m2[it->first]>0){
                ans.push_back(it->first);
            }
         }
        }
        else{
        unordered_map<int,int>::iterator it;
        for(it=m2.begin();it!=m2.end();it++){
            if(m1[it->first]>0){
                ans.push_back(it->first);
            }
         } 
        }
        return ans;
    }
};