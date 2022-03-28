class Solution {
public:
    int binarySerach(vector<int>& m){
        int left = 0,right = m.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(m[mid] == 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> p;
        vector<int> res;
        int n = mat.size();
        for(int i = 0;i < n;i++){
            int count = binarySerach(mat[i]);
            p.push(make_pair(count,i));
            if(p.size() > k)
                p.pop();
        }
        for(int i = 0;i < k;i++){
            res.push_back(p.top().second);
            p.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};