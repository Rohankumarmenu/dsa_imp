
class Solution {
  public:

    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
          vector<vector<int>> adj(V+1);
        int u,v;
        int m=edges.size();
        for(int i=0;i<m;i++){
             u=edges[i].first;
             v=edges[i].second;
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        return adj;
    }
};