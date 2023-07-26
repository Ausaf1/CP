class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr = start^goal,count = 0;
        while(xr){
            xr &= (xr - 1);
            count++;
        }
        return count;
    }
};