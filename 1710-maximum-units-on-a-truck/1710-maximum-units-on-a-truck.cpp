class Solution {
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int n = boxTypes.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(boxTypes[i][0] <= truckSize && truckSize > 0)
                ans += boxTypes[i][1]*boxTypes[i][0],truckSize-=boxTypes[i][0];
            else {
                int c = truckSize;
                truckSize -= c;
                ans += c*boxTypes[i][1];
            }
        }
        return ans;
    }
};