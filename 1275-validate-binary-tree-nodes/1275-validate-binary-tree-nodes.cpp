class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> childToPar;
        unordered_map<int,vector<int>> adj;
        for(int i = 0;i < n;i++){
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];
            if(leftC != -1){
                adj[i].push_back(leftC);
                if(childToPar.find(leftC) != childToPar.end()) return false;
                childToPar[leftC] = node;
            }
            if(rightC != -1){
                adj[i].push_back(rightC);
                if(childToPar.find(rightC) != childToPar.end()) return false;
                childToPar[rightC] = node;
            }
        }
        int root = -1;
        for(int i = 0;i < n;i++){
            if(childToPar.find(i) == childToPar.end()){
                if(root != -1) return false;
                root = i;
            }
        }
        if(root == -1) return false;
        queue<int> q;
        q.push(root);
        int count = 1;
        vector<int> visited(n,false);
        visited[root] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        return count == n;
    }
};