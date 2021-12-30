class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
          string s;
        if(digits.length() == 0){
            return ans;
        }else{
            switch(digits.at(0)){
                case '2': s = "abc"; break;
                case '3': s = "def"; break;
                case '4': s = "ghi"; break;
                case '5': s = "jkl"; break;
                case '6': s = "mno"; break;;
                case '7': s = "pqrs"; break;
                case '8': s = "tuv"; break;
                case '9': s = "wxyz"; break;
            }
        }
            vector<string> rest = letterCombinations(digits.erase(0, 1));
            for(int i = 0; i < s.length(); i++){
                if(rest.size() == 0){
                    ans.push_back(s.substr(i,1));
                }else{
                    for(int j = 0; j < rest.size(); j++){
                       ans.push_back(s.at(i) + rest[j]);
                    }
                }
            }
            return ans;
    }
};