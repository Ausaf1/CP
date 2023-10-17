class Solution {
private:
    int find(int x,vector<int> &parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x],parent);
    }
    bool Union(int p,int c,int &components,vector<int> &parent){
        if(find(c,parent) != c) return false;
        if(find(p,parent) == c) return false;
        parent[c] = p;
        components -= 1;
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
        int components = n;
        for(int i = 0;i < n;i++){
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];
            if(leftC != -1 && Union(node,leftC,components,parent) == false) return false;
            if(rightC != -1 && Union(node,rightC,components,parent) == false) return false;
        }
        return components == 1;
    }
};