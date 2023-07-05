class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mnSize = INT_MAX;
        string str;
        for(int i = 0;i < strs.size();i++){
            if(strs[i].size() < mnSize){
                mnSize = strs[i].length();
                str = strs[i];
            }
        }
        int count = 0;
        for(int i = 0;i < mnSize;i++){
            for(int j = 0;j < strs.size();j++){
                if(strs[j][i] != str[i]) return str.substr(0,count);
            }
            count++;
        }
        return str.substr(0, count);
    }
};