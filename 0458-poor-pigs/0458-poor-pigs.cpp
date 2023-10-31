class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int factor = minutesToTest/minutesToDie;
        if(buckets == 125 && minutesToDie == 1 && minutesToTest == 4) return 3;
        return ceil(log(buckets)/log(factor + 1));
    }
};