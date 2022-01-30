class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long t = 0;
        for(auto n : chalk) t += n;
        int r = (long long)k % t;
        for(int i = 0;i < chalk.size();i++){
            r -= chalk[i];
            if(r < 0)
                return i;
        }
        return 0;
    }
};