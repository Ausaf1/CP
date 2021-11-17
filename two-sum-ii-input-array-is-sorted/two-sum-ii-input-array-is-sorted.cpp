class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int l = 0,r = numbers.size()-1;
        // while(l<r){
        //     if(numbers[l]+numbers[r] == target){
        //         return {l+1,r+1};
        //     }
        //     else if(numbers[l]+numbers[r] > target){
        //         r--;
        //     }
        //     else{
        //         l++;
        //     }
        // }
        // return {};
        int l = 0,r = numbers.size()-1;
        sort(numbers.begin(),numbers.end());
        while(l<r){
          int mid = (l+r)/ 2;
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            } else if (numbers[l] + numbers[r] < target) {
                if (numbers[mid] + numbers[r] == target) {
                    return {mid + 1, r + 1};
                } else if (numbers[mid] + numbers[r] < target) {
                    l = mid + 1;
                } else {
                    l++;
                }
            } else {    
                if (numbers[l] + numbers[mid] == target) {
                    return {l + 1, mid + 1};
                } else if (numbers[l] + numbers[mid] > target) {
                    r = mid - 1;
                } else {
                    r--;
                }
            }
        }
        return {};
    }
};