class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> res;
       for(auto c : intervals){
           if(c[1] < newInterval[0]) res.push_back(c);
           else if(newInterval[1] < c[0]){
               res.push_back(newInterval);
               newInterval = c;
           }
           else{
               newInterval[0] = min(newInterval[0],c[0]);
               newInterval[1] = max(newInterval[1],c[1]);
           }
       } 
        res.push_back(newInterval);
        return res;
    }
};