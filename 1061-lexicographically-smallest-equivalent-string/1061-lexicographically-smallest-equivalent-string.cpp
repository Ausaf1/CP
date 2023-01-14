class Solution {
public:
vector<int> parent;
    int find(int x){
        if(parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        x = find(x),y = find(y);
        if(x != y) parent[max(x,y)] = min(x,y);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26,-1);
        for(int i = 0;i < s1.length();i++) Union(s1[i] - 'a',s2[i] - 'a');
        for(int i = 0 ;i < baseStr.length();i++) baseStr[i] = find(baseStr[i] - 'a') + 'a';
        return baseStr;
    }
};