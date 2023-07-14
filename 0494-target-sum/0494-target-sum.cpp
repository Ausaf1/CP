class Solution {
public:
   int solveWithMemo(vector<int>& nums, int target, int sum, int index, unordered_map<string, int>& memo) {
    if(index == nums.size()) {
        if(sum == target)
            return 1;
        else
            return 0;
    }

    string key = to_string(index) + "-" + to_string(sum);

    if(memo.count(key))
        return memo[key];
    int takePos = solveWithMemo(nums, target, sum + nums[index], index + 1, memo); 
    int takeNeg = solveWithMemo(nums, target, sum - nums[index], index + 1, memo);
    return memo[key] = takePos + takeNeg;
}

int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<string, int> memo;
    return solveWithMemo(nums, target, 0, 0, memo);
}
};