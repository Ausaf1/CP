class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        int t = n;
        int m = 1e9 + 7;
        while(t > 0){
            res *= t--;
            res %= m;
        }
        int x = 1;
        while(2*n-x > 0){
            res *= (2*n - x);
            x += 2;
            res %= m;
        }
        return res;
    }
};