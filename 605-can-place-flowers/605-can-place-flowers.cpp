class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int ans=0, m=flowerbed.size();
        for(int i=0; i<flowerbed.size();i++){
            if(flowerbed[i]==0 && (i==m-1 || flowerbed[i+1] == 0) && (i==0 || flowerbed[i-1] == 0)){
                ans += 1;
                flowerbed[i]=1;
            }
        }
        return ans>=n ? true : false;
    }
};