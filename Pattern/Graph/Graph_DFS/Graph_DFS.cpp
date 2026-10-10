class Solution {
  public:
  void recurse(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&store){
      vis[node]=1;
      store.push_back(node);
      for(auto it:adj[node]){
          if(!vis[it]){
              recurse(it,adj,vis,store);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
          int V=adj.size();
          vector<int>vis(V,0);
        //   int vis[V]={0};
          int start=0;
          vector<int>store;
          recurse(start,adj,vis,store);
          return store;
          
    }
};