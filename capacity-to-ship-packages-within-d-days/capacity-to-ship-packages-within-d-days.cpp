class Solution {
public:
    int check(vector<int>& weights, int ship_capacity){
        int number_of_ships_needed =1;
        int currently_filled = 0;
        for(int i = 0;i<weights.size();i++){
            if(ship_capacity-currently_filled>=weights[i]){
                currently_filled += weights[i];
            }
            else{
                number_of_ships_needed++;
                currently_filled = weights[i];
            }
        }
        return number_of_ships_needed;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lower_limit = *max_element(weights.begin(),weights.end());
        int upper_limit = accumulate(weights.begin(),weights.end(),0);
        while(lower_limit<upper_limit){
           int mid = (lower_limit+upper_limit)/2;
            if(check(weights,mid)>days){
                lower_limit = mid+1;
            }
            else{
                upper_limit = mid;
            }
        }
        return lower_limit;
    }
};