class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long start = 1;
        row.push_back(start);
        for(int i = 0;i < rowIndex;i++){
            start *= (rowIndex - i);
            start /= (i + 1);
            row.push_back(start);
        }
        return row;
    }
};