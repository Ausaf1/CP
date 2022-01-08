class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        set<pair<double,int>> s;
        for(int i = 0;i<n;i++) {
            vector<int> point = points[i];
            s.insert({sqrt(pow(points[i][0],2)+pow(points[i][1],2)),i});
        }
        int i = 0;
        for(auto it : s){
            int a = it.second;
            ans.push_back(points[a]);
            i++;
            if(k == i)
                break;
        }
        return ans;
    }
};